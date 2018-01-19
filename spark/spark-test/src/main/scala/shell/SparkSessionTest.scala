package shell
import org.apache.spark.sql.types._
import org.apache.spark.sql.{Row, SparkSession}
import org.apache.spark.sql.types.{StructField, StructType}

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-1-17
 *
 */
class SparkSessionTest {

}

object SparkSessionTest {

  def main(args: Array[String]): Unit = {
    val sparkSession =   SparkSession.builder()
      .appName("DataSet Test")
      .config("spark.serializer", "org.apache.spark.serializer.KryoSerializer")
      .config("spark.rdd.compress", "true")
      .config("spark.io.compression.codec", "snappy")
      .config("spark.sql.warehouse.dir", "s3://mob-emr-test/spark-warehouse")
      .getOrCreate()

    // 获取数据
    val testSql = sparkSession
      .read
      .text("s3://mob-emr-test/dongtao/mobvista/ods_adn_trackingnew/2017/02/02/23").as[String].toJavaRDD

    // 截取字段
    val colGet = testSql.filter((vLine:String) =>{
      if(vLine.split("\t").size > 36){
        true
      }else{
        false
      }
    }).map((vLine:String) => {
      val adnEle = vLine.split("\t")

      val adnMap:Map[String,String] = Map(
        "publisher_id"-> adnEle(2),
        "app_id" -> adnEle(3),
        "ad_type"-> adnEle(8),
        "device_model" -> adnEle(13),
        "impression" -> adnEle(36)
      )
      adnMap
    })

    // 按照　device_model:app_id 聚合求展现量
    val result = colGet.map((eleMap:Map[String,String])=>{(eleMap("device_model") + ":" + eleMap("app_id"), eleMap("impression").asInstanceOf[Int])})
         .reduceByKey(_+_)
         .sortBy(f=_._2, ascending = true)
         .map((ele)=>{
           val key = ele._1.split(":")
           Row(key(0),key(1),ele._2)
         })

    val schema:StructType = StructType(Seq(
      StructField("device_model", StringType, false),
      StructField("app_id", StringType, false),
      StructField("impression", IntegerType, false))
    )


    val  adnDF = sparkSession.createDataFrame(result, schema)

    adnDF.write.parquet("s3://mob-emr-test/dongtao/tmp/ods_adn_trackingnew")
  }
}
