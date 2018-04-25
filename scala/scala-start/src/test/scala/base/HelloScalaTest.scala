package base

import org.junit.Test
import test.base.MyMatcher

/**
 * Created by saligia on 17-9-6.
 *
 *
 */

// s3://mob-emr-test/wanjun/m_sys_model/feature_process/*/20180419/2018041912
// s3://mob-emr-test/wanjun/m_sys_model/feature_process/*/20180419/test/2018041912
// s3://uparpu/dev/uparpu_main/uparpu_tk_request_count_hour_tmp/yyyy=2018/mm=04/test/dd=20/hh=00

class HelloScalaTest {
  @Test
  def testStart():Unit={
    val logMsg = "s3://uparpu/dev/uparpu_main/uparpu_tk_request_count_hour_tmp/yyyy=2018/mm=04/test/dd=20/hh=00"

    val urlReg = """(.*?)(/[a-zA-Z=]*[\*\d]{1,})+(/[a-zA-Z]{1,})?.*""".r

    logMsg match{
      case urlReg(master,  application, test ) =>{

        if(test == null){
          println("NULL")
        }
        println(s"[${master}] :  [${application}] : [${test}]")
      }
      case _ =>{
        println("cao")
      }
    }



  }
}
