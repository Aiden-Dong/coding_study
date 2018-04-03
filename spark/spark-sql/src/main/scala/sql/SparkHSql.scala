package sql

import org.apache.spark.sql.SparkSession

/**
 * <pre>
 *   spark-sql
 * </pre>
 *
 * @author saligia
 * @date 18-3-26
 *
 */
object SparkHSql extends App{
  val spark = SparkSession.builder()
    .appName("SparkSQL_Test")
    .config("spark.rdd.compress", "true")
    .config("spark.io.compression.codec", "snappy")
    .config("spark.sql.inMemoryColumnarStorage.compressed", "false")
    .config("spark.sql.inMemoryColumnarStorage.batchSize", "1000")
    .config("spark.sql.warehouse.dir", "s3://mob-emr-test/spark-warehouse")
    .config("spark.serializer", "org.apache.spark.serializer.KryoSerializer")
    .config("spark.sql.hive.inputformat","org.apache.hadoop.mapreduce.lib.input.CombineTextInputFormat")
    .enableHiveSupport()
    .getOrCreate()

  val sql = args(1)
  val textFile = args(0)

  try{
    val catchSql = spark.conf.get("spark.user.cache.sql")
    spark.sql(catchSql)
  }catch {
    case e: NoSuchElementException =>{}
  }

  spark.sparkContext.

  val sql1 = spark.sql(sql).repartition(20)
    .write.format("csv")
    .option("sep", "\t")
    .save(textFile)

  spark.stop();
}
