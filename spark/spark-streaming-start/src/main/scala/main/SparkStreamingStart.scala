package main

import org.apache.spark.streaming.{Seconds, StreamingContext}
import org.apache.spark.{SparkConf, SparkContext}


/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 17-10-31
 *
 */
object SparkStreamingStart extends App{

  // 初始化 spark
  val conf:SparkConf = new SparkConf().setAppName("Spark-Streaming-Start")
  val sc:SparkContext = new SparkContext(conf)
  val ssc:StreamingContext = new StreamingContext(conf,  Seconds(1))

  /**
   * 创建 DStream
   * 表示从 TCP 源（主机 : localhost, 端口 9999）获取到的流式数据。
   */

  /**
   * 这个 lines 变量是一个 DStream，表示即将从数据服务器获得的流数据。
   * 这个DStream的每条记录都代表一行文本。 下一步， 我们需要将DStream中的每行文本都切分为单词。
   */
  val lines = ssc.socketTextStream("localhost", 9999)

  /**
   * flatMap 是一个一对多的DStream操作，它通过把源DStream的每条记录都生成多条新记录来创建一个新的DStream。
   * 在这个例子中，每行文本都被切分成了多个单词，我们把切分的单词流用 words 这个DStream表示。
   * 下一步， 我们需要计算单词的个数。
   *
   * words 这个DStream被mapper(一对一转换操作)成了一个新的DStream， 它由（ word,1）对组成。
   * 然后，我们就可以用这个新的DStream计算每批数据的词频。 最后， 我们用 wordCounts.print() 打印每秒计算的词频。
   */

  val word = lines.flatMap(_.split(","))
  val pairs = word.map((_,1))
  val wordCounts = pairs.reduceByKey(_+_)

  wordCounts.print()

  /**
   * 需要注意的是，当以上这些代码被执行时， Spark Streaming仅仅准备好了它要执行的计算，
   * 实际上并没有真正开始执行。 在这些转换操作准备好之后， 要真正执行计算， 需要调用如下的方法
   */
  ssc.start()
  ssc.awaitTermination()

}
