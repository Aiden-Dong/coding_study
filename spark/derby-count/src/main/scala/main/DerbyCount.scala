package main

import org.apache.spark.storage.StorageLevel
import org.apache.spark.{SparkConf, SparkContext}

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 17-10-31
 *
 */
object DerbyCount extends App{

  // 创建 spark config
  val sparkConf:SparkConf = new SparkConf().setAppName("derbyContext")
  // 创建 spark context
  val sparkContext:SparkContext = new SparkContext(sparkConf)


  // textFile
  val derbyRdd = sparkContext.textFile("/data/input/derby.log")

  // wholeTextFiles
  val wholeRdd = sparkContext.wholeTextFiles("/data/input")

  sparkContext.longAccumulator("test")

  derbyRdd.persist(StorageLevel.DISK_ONLY)
  derbyRdd.flatMap(_.split(",")).map((_,1)).reduceByKey(_+_).foreach(data=>{
    if(data._2 > 10){
      println(data._1)
    }
  })
}
