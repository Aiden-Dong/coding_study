package test

import org.apache.hadoop.io.{LongWritable, Text}
import org.apache.hadoop.mapreduce.lib.input.CombineTextInputFormat
import org.apache.spark.rdd.RDD
import org.apache.spark.sql.SparkSession

/** *
 * <pre>
 *   world count
 * </pre>
 *
 * @user : saligia
 * @date : 2018-05-31
 */
object CombinerApplication {

  def main(args: Array[String]): Unit = {

    val sparkSession:SparkSession = SparkSession.builder()
      .config("spark.serializer", "org.apache.spark.serializer.KryoSerializer")
      .config("spark.rdd.compress", "true")
      .config("spark.io.compression.codec", "snappy")
      //.config("spark.shuffle.file.buffer", "1G")
      .config("spark.default.parallelism", "200")
      .getOrCreate()


    val inputPath = args(0)
    val outputPath = args(1)

    val data:RDD[(LongWritable, Text)] = sparkSession.sparkContext.newAPIHadoopFile[LongWritable, Text, CombineTextInputFormat](inputPath)
    //val data:RDD[String] = sparkSession.sparkContext.textFile(inputPath)

    val result = data.flatMap(_._2.toString.split("\t"))
        .map((_, 1))
        .reduceByKey(_+_)

    result.saveAsTextFile(outputPath)

    sparkSession.close()
  }

}
