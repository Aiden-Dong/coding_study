package implicate

import java.io.File

import org.junit.Test

import scala.io.Source

/**
 * <pre>
 *   测试隐式转换相关注意与功能
 * </pre>
 *
 * @author saligia
 * @date 18-3-27
 *
 */
class ImplicateTest {

  /**
   * <pre>
   *   提供了从　float 到　Int 的隐式转换函数 :
   *   　 隐式函数的名称对结构没有影响，
   *      即 implicit def double2Int(x:Double)=x.toInt 函数可以是任何名字，
   *      只是采用source2Target这种方式函数的意思比较明确，阅读代码的人可以见名知义，增加代码的可读性。
   * </pre>
   *
   * @author
   * @param
   * @return
   */
  implicit def double2Int(double: Double):Int ={
    return double.toInt
  }

  @Test
  def testImplicateFunction(): Unit ={
    val a:Int = 3.12
  }

  class RichFile(file:File){
    def read():String = {
      Source.fromFile(file).mkString
    }
  }

  implicit def file2RichFile(file:File):RichFile = {
    new RichFile(file)
  }

  @Test
  def testfileSource ():Unit = {
    val file = new File("");
    file.read()
  }
}
