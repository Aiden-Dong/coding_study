package job

import org.apache.spark.sql.SparkSession

/** *
 * <pre>
 *   spark 测试工具类
 * </pre>
 *
 * @user : saligia
 * @date : 2018-07-24
 */
object SparkAppTest {
  def main(args: Array[String]): Unit = {

    val sparkSession = SparkSession.builder()
      .getOrCreate()

    val inputPath = args(0)
    val outputPath = args(1)


    val rdd = sparkSession.read.textFile(inputPath).rdd

    rdd.flatMap((line:String) =>{
      line.split(" ")
    }).map((_,1))
      .reduceByKey(_+_)
      .saveAsTextFile(outputPath)

    sparkSession.close()
  }
}
