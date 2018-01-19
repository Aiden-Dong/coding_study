package sql

import org.apache.spark.sql.SparkSession

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-1-15
 *
 */
object SparkSqlTest extends App{

  val spark = SparkSession.builder()
    .appName("SparkSQL_Test")
    .config("spark.rdd.compress", "true")
    .config("spark.io.compression.codec", "snappy")
    .config("spark.sql.warehouse.dir", "s3://mob-emr-test/spark-warehouse")
    .config("spark.serializer", "org.apache.spark.serializer.KryoSerializer")
    .enableHiveSupport()
    .getOrCreate()

  val textFile = args(1)
  val sql =args(0).stripMargin

  val sql1 = spark.sql(sql).repartition(10)
    .write.format("csv")
    .option("sep", "\t")
    .save(textFile)

  spark.stop()

  System.exit(0)

}
