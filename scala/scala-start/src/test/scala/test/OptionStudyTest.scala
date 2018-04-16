package test

import org.junit.Test

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-4-16
 *
 */
class OptionStudyTest {

  @Test
  def testGetOption(): Unit ={
    System.out.println(OptionStudy.getOption().getOrElse())
  }
}
