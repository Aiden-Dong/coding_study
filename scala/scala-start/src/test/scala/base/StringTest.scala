package base

import org.junit.Test

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 2018-04-25
 */
class StringTest{

  @Test
  def testStringFormat(): Unit ={
    val test="gogo"
    val strVal = s"""hello "${test}" world"""

    println(strVal)
  }
}
