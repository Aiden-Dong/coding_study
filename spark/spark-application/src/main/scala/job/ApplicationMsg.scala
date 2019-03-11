package job

import java.util.Properties

import org.apache.spark.sql.SparkSession

/**
 * <pre>
 * 获取一天的Application作业
 *     1. 按照队列
 *     2. 按照集群，队列进行分组
 *     3. 获取每天 core 的占用情况聚合
 *     4. 资源占用情况聚合
 *     5. 作业数量
 * master_ip               string                  yarn master ip
 * master_name             string                  yarn master name
 * application_id          string                  application id
 * application_name        string                  application_name
 * application_type        string                  application flag : HIVE MapReduce Spark
 * user_name               string                  application commint user name
 * queue_name              string                  application run queue name
 * application_status      string                  application status
 * application_core        int                     application core
 * application_memory      double                  application memory GB
 * application_start_time  bigint                  applica tion start time
 * application_stop_time   bigint                  application stop time
 * application_elapsed_time        int                     application elapsed time
 * application_read_byte   bigint                  application read byte
 * application_input_dir   string                  application input dir
 * application_output_dir  string                  application output dir
 * </pre>
 *
 * @author saligia
 * @date 2018-04-27
 */
object ApplicationMsg {

  val config = {
    val proStream = getClass.getClassLoader.getResourceAsStream("config.properties")
    val properties = new Properties()
    properties.load(proStream)
    proStream.close()
    properties
  }

  // 这个应用程序我们应该定义一个 main() 方法而不是去扩展 scala.App
  // 使用 scala.App 的子类可能不会正常运行。
  def main(args: Array[String]): Unit = {
    val spark:SparkSession = SparkSession.builder()
      .appName("ApplicationCounter-Dongtao")
      .getOrCreate()

    val textFile = config.getProperty("spark-input-files")
    val saveFile = config.getProperty("spark-output-files")

    val dataRDD = spark.read.textFile(textFile).rdd


    /**
     * 0 master_ip               string                  yarn master ip
     * 1 master_name             string                  yarn master name
     * 2 application_id          string                  application id
     * 3 application_name        string                  application_name
     * 4 application_type        string                  application flag : HIVE MapReduce Spark
     * 5 user_name               string                  application commint user name
     * 6 queue_name              string                  application run queue name
     * 7 application_status      string                  application status
     * 8 application_core        int                     application core
     * 9 application_memory      double                  application memory GB
     *10 application_start_time  bigint                  applica tion start time
     *11 application_stop_time   bigint                  application stop time
     *12 application_elapsed_time      int                     application elapsed time
     *13 application_read_byte   bigint                  application read byte
     *14 application_input_dir   string                  application input dir
     *15 application_output_dir  string                  application output dir
     *
     */

    dataRDD.map(_.split("\t"))   // 切分数据
      .map(applicationMsg=>{
      val queueName = applicationMsg(6)
      val queueNameNew = if(queueName.contains("3s")){  // 队列映射
        "3ssystem"
      }else if(queueName.contains("dataplatform")){
        "dataplatform"
      }else if(queueName.contains("engineer")){
        "engineer"
      }else if(queueName.contains("msystem")){
        "msystem"
      }else if(queueName.contains("scientist")){
        "scientist"
      }else{
        queueName
      }
      // applicationMsg

      ((applicationMsg(1),queueNameNew),
        (applicationMsg(8).toInt,       // application_core
          applicationMsg(9).toDouble,         // application_memory
          applicationMsg(8).toInt*applicationMsg(12).toLong,
          applicationMsg(9).toDouble*applicationMsg(12).toLong,
          applicationMsg(12).toLong,    // application_elapsed_time
          applicationMsg(13).toLong,    // application_read_byte
          1)                              // application_num
      )
    }).reduceByKey((t1, t2)=>{
      (t1._1+t2._1,
        t1._2 + t2._2,
        t1._3 + t2._3,
        t1._4 + t2._4,
        t1._5 + t2._5,
        t1._6 + t2._6,
        t1._7 + t2._7)
    }).map(groupRDD=>{
        s"${groupRDD._1._1},${groupRDD._1._2},"+
        s"${groupRDD._2._1.toString},"+
        s"${groupRDD._2._2.toString},"+
        s"${groupRDD._2._3.toString},"+
        s"${groupRDD._2._4.toString},"+
        s"${groupRDD._2._5.toString},"+
        s"${groupRDD._2._6.toString},"+
        s"${groupRDD._2._7.toString}"
    }).repartition(1).saveAsTextFile(saveFile)

    spark.stop()
  }
}
