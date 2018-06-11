package `match`

import java.io.{BufferedReader, InputStreamReader}

import study.ApplicationKill

import scala.io.Source

/** *
 * <pre>
 *   作业匹配
 * </pre>
 *
 * @user : saligia
 * @date : 2018-06-07
 */
class ApplicationMatch {
  def applicationMath():Unit={

    val inputStream = classOf[ApplicationMatch].getClassLoader.getResourceAsStream("application_path.log")
    val applicationLog = Source.fromInputStream(inputStream)
    val PathMatcher = """^s3://(.*?)/([yearYEAR=]*?\d{4}).*?(/?[monthMonth=]*?\d{2}).*?(/?[dayDAY=]*?\d{2}).*?(/?[HOURhour=]*?\d{2})?.*?(/?[minuteMINUTE=]*?\d{2})?$""".r

    for(appPath <- applicationLog.getLines()){
      appPath match {
        case PathMatcher(path, year, month, day, hour, minute) =>{
          println(appPath)
          println(s"path : ${path}, year : ${year}, month : ${month}, day : ${day}, hour : ${hour}, minute : ${minute}")
        }
        case _=>{
          println(s"error match ${appPath}")
        }
      }
    }
  }
}
