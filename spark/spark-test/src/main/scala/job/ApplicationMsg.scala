package job

import org.apache.spark.{SparkConf, SparkContext}
import org.apache.spark.sql.SparkSession

/**
 * <pre>
 *   获取一天的Application作业
 *   1. 按照队列
 *   2. 按照集群，队列进行分组
 *   3. 获取每天 core 的占用情况聚合
 *   4. 资源占用情况聚合
 *   5. 作业数量
 *
 * 0 master_ip varchar(50) NOT NULL COMMENT 'yarn master ip',
 * 1 master_name varchar(50) NOT NULL COMMENT 'yarn master name',
 * 2 user_name varchar(50) NOT NULL COMMENT 'application commint user name',
 * 3 queue_name varchar(50) NOT NULL COMMENT 'application run queue name',
 * 4 application_id varchar(50) NOT NULL UNIQUE KEY COMMENT 'application id',
 * 5 application_name varchar(200) NOT NULL COMMENT 'application_name',
 * 6 application_type varchar(200) COMMENT 'application flag : HIVE MapReduce Spark',
 * 7 application_status varchar(10) COMMENT 'application status',
 * 8 application_core  int(8) NOT NULL COMMENT 'application core',
 * 9 application_memory float(20) NOT NULL COMMENT 'application memory GB',
 *10 application_start_time bigint(20) NOT NULL COMMENT 'application start time',
 *11 application_stop_time bigint(20) NOT NULL COMMENT 'application stop time',
 *12 application_elapsed_time int(10) NOT NULL COMMENT 'application elapsed time',
 *13 application_read_byte bigint(20) NOT NULL COMMENT 'application read byte',
 *14 application_input_dir text NOT NULL COMMENT 'application input dir',
 *15 application_output_dir text NOT NULL COMMENT 'application output dir'
 *
 * </pre>
 *
 * @author saligia
 * @date 2018-04-26
 */
object ApplicationMsg  {

  // 这个应用程序我们应该定义一个 main() 方法而不是去扩展 scala.App
  // 使用 scala.App 的子类可能不会正常运行。
  def main(args: Array[String]): Unit = {
    val spark:SparkSession = SparkSession.builder()
      .appName("ApplicationCounter-Dongtao")
      .getOrCreate()

    val textFile = spark.conf.get("spark-input-files")
    val saveFile = spark.conf.get("spark-output-files")

    val dataRDD = spark.read.textFile(textFile).rdd

    dataRDD.map(_.split("\t"))    // 切分数据
      .map(applicationArray =>{       // (master_name, queue_name, application_core, application_memory, application_read_byte)
      (s"${applicationArray(2)}:${applicationArray(3)}",
        (applicationArray(7).toInt,       // application_core
          applicationArray(8).toDouble,   // application_memory
          applicationArray(7).toInt*applicationArray(12).toLong,
          applicationArray(8).toDouble*applicationArray(12).toLong,
          applicationArray(12).toLong,    // application_elapsed_time
          applicationArray(13).toLong,    // application_read_byte
          1)                              // application_num
      )}).reduceByKey((t1, t2)=>{
      (t1._1+t2._1,
        t1._2 + t2._2,
        t1._3 + t2._3,
        t1._4 + t2._4,
        t1._5 + t2._5,
        t1._6 + t2._6,
        t1._7 + t2._7)}
    ).saveAsTextFile(saveFile)

    spark.stop()
  }

}
