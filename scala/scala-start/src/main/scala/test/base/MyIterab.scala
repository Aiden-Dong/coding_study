package test.base

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 17-10-2
 *
 */
object MyIterab {

  /**
   * <pre>
   *   Vector-- 支持随机访问
   * </pre>
   *
   * @author
   * @return
   */
  def getVectory():Unit = {
    val vector:Vector[String] = Vector[String]("one", "two", "three")

    println(vector(1))

    val buffer:ArrayBuffer[String] = new ArrayBuffer[String]()

    buffer += "one"
  }

  def getArrayBuffer():Unit = {
    val buffer:ArrayBuffer[String] = new ArrayBuffer[String]()

    buffer += "one"

    buffer += "cat"

    for(ele <- buffer){
      println(ele )
    }
  }

  def getList():Unit = {
    var list:List[Int] = List(5,8)

    // 添加元素
    list = 8::list


    for (ele <- list){
      println(ele)
    }
  }

  def getRange():Unit = {
    val range = new Range(1, 10, 2)   // Range 保留其实位置和结束位置，还有步条

    for(ele <- range){
      println(ele)
    }
  }

  def getStack():Unit = {

    val stak:mutable.ArrayStack[String] = new mutable.ArrayStack[String]()


    stak.push("one")
    stak.push("two")
    stak.push("three")

    println(stak.pop())
  }

  def getQueue():Unit = {
    val queue:mutable.PriorityQueue[String] = new mutable.PriorityQueue[String]()

  }

  def getLinkedList():Unit = {
   val lst = mutable.LinkedList(1, -2, 7, -9)
  }

}
