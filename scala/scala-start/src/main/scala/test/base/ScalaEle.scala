package test.base

import java.util

import scala.collection.mutable.ArrayBuffer

/**
  * <pre>
  *   scala 基础性元素,包括数组, 列表,元组, 映射
  * </pre>
  *
  * @author saligia
  * @date 17-9-26
  */
object ScalaEle {

  /**
   *<pre>
    *   定长数组 get
   *</pre>
   *
   *@author {USER}
   *@param null
   *@return
   */
  def getArray(): Unit ={
    val array:Array[String] = Array("12", "13", "14", "15")
    val str = UtilParse.objectToJson(array)
    println(str)
  }

  def getArrayBuffer():Unit ={
    /*
    * ArrayBuffer 无法完成正常映射
     */
    // val arrayBuffer = new ArrayBuffer[String]()
    // arrayBuffer.append("12", "13", "14")

    /*
    * List 容器可以完成
     */
    val arrayBuffer:util.List[String] = new util.LinkedList[String]();

    arrayBuffer.add("12")
    arrayBuffer.add("13")
    println(UtilParse.objectToJson(arrayBuffer))
  }

  def getMapMsg():Unit={
    val map:util.HashMap[String, OneObj] = new util.HashMap[String, OneObj]()


    map.put("saligia", new OneObj("saligai", 20))
    map.put("eva", new OneObj("eva", 13))

    println(UtilParse.objectToJson(map))
  }

}
