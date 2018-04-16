package test

import org.junit.Test
import test.interface.Logger

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-4-16
 *
 */
class SingleonStudyTest {

  object MyLog extends Logger{
    override def logger(msg: String): Unit = {
      println(msg)
    }
  }
  @Test
  def testShowMsg(): Unit ={
    SingletonStudy.showMsg("======================", MyLog)
  }
}
