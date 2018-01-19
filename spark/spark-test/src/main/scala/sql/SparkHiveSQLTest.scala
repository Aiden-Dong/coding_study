package sql

import org.apache.spark.sql.hive.HiveContext
import org.apache.spark.{SparkConf, SparkContext}

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-1-15
 *
 */
object SparkHiveSQLTest extends App{

  val conf:SparkConf = new SparkConf().setAppName("SparkHiveSQl Test")
  val sc:SparkContext = new SparkContext(conf)
  val hsql:HiveContext = new HiveContext(sc)

  hsql.sql("show databases").show(20)
}
