package shell

import org.apache.spark.{SparkConf, SparkContext}

import scala.collection.mutable.ArrayBuffer

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 17-10-18
 *
 */
object SparkTest extends App{

  val conf = new SparkConf().setAppName("SparkTest")
  val arrayBuffer:ArrayBuffer[String] = new ArrayBuffer();
  val sc = new SparkContext(conf)

  //val textFile= sc.textFile("s3://mob-emr-test/dongtao/mobvista/tmp/testData")


  //val count = textFile.flatMap(_.split(" ")).map((_,1)).reduceByKey(_+_).count()
  //println(count)
  val rdd = sc.parallelize(args)
  rdd.foreach(println(_))
}
