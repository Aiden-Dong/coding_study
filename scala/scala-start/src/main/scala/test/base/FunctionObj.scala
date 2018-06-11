package test.base

import scala.collection.mutable.ArrayBuffer

/**
 * <pre>
 *  scala 函数性质
 * </pre>
 *
 * @author saligia
 * @date 17-9-30
 *
 */
object FunctionObj {

  /**
   * <pre>
   *   可变参数
   * </pre>
   *
   * @author saligia
   * @param params
   * @return null
   */
  def printString(params:String*): Unit ={

    for (str <- params){
      println(str)
    }
  }

  def printRefrence(test:String, array:ArrayBuffer[String]=ArrayBuffer()):String = {
    array += test
    return array.toString()
  }

  /**
   * <pre>
   *   匿名函数
   * </pre>
   *
   * @author saligia
   * @param x
   * @return 3*x
   */
  val tripe = (x:Double) => x*3

  val tripes = (x:Double) => {
    x*3
  }


  /**
   * <pre>
   *   函数参数
   * </pre>
   *
   * @author
   * @param fcunction
   * @return
   */

  def getValue(x:Double, func : (Double)=>Double) : Double = {
    func(x)
  }


  /**
   * <pre>
   *    参数推断
   * </pre>
   *
   * @author saligia
   * @param
   * @return
   */
  def getValues(func:(Double, Double) => Double) :Double = {
    func(6,10)
  }

  /**
   * <pre>
   *   编写函数 largest(func:(Int)=>Int, inputs:Seq[Int]) , 返回给定函数应用到给定序列中的最大值。
   * </pre>
   *
   * @author saligia
   * @param func
   * @param inputs
   * @return targetInt
   */
  def largest(func:(Int)=>Int, inputs:Seq[Int]): Int ={
    val maxValue  = inputs.maxBy(func)
    func(maxValue)
  }

  /**
   * <pre>
   *   对偶求和
   * </pre>
   *
   * @author saligia
   * @param
   * @return
   */

  def map(func:((Int, Int))=>Int, one:(Int,Int)):Int ={
    func(one._1, one._2)
  }

  val isEnableAssert = true
  // 使用正常的函数定义
  def simpleAssert(predicate: () => Boolean) = {
    if (isEnableAssert && !predicate())
      throw new AssertionError()
  }

  //  simpleAssert( 2 > 3) 会报错
  simpleAssert(() => 2 > 3)

  // 为了省略()=> 可以使用 by name 参数
  def byNameAssert(predicate: => Boolean) = {
    if (isEnableAssert && !predicate)
      throw new AssertionError()
  }

  byNameAssert(predicate = {1 > 2; true})
}

