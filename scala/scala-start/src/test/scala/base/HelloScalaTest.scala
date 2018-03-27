package base

import org.junit.Test
import test.base.MyMatcher

/**
  * Created by saligia on 17-9-6.
  */
class HelloScalaTest {
  @Test
  def testStart():Unit={
    MyMatcher.testArray()
  }
}
