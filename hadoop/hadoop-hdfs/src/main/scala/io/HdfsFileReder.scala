package io

import java.io.{BufferedReader, InputStreamReader}
import java.net.URI

import org.apache.hadoop.conf.Configuration
import org.apache.hadoop.fs.{FileSystem, Path}

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

/** *
 * <pre>
 * </pre>
 *
 * @user : saligia
 * @date : 2018-06-04
 */
object HdfsFileReder {

  def main(args: Array[String]): Unit = {
    val logPath = "hdfs://ip-172-31-23-44.ec2.internal:8020/var/log/hadoop-yarn/apps/hadoop/logs/application_1528084924709_0637/ip-172-31-22-19.ec2.internal_8041"
    val hadoopConfig = new Configuration()
    val hdfsFile = FileSystem.get(URI.create(logPath), hadoopConfig)
    //val hdfsStat = hdfsFile.getFileStatus(new Path(logPath))
    //(.*?)(/[a-zA-Z=]*[\*\d]{1,})+(/[a-zA-Z]{1,})?.*

    val OutputMatch = ".*MultipartUploadOutputStream: close closed:false (s3.*?)(/[a-zA-Z=\\-]*[\\*\\d]{1,})+(/[a-zA-Z]{1,})?".r
    val InputMatch = ".*Opening '(s3.*?)(/[a-zA-Z=\\-]*[\\*\\d]{1,})+(/[a-zA-Z]{1,})?' for reading".r

    var inPathSet = mutable.HashSet[String]()
    var outPathSet = mutable.HashSet[String]()

    var fin:BufferedReader  = null;
    try{
      fin = new BufferedReader(new InputStreamReader(hdfsFile.open(new Path(logPath))))
      var textLine:String = null
      while(fin.ready()){
        fin.readLine() match {
          case OutputMatch(mainPath, parPath, inPath) => outPathSet += mainPath
          case InputMatch(mainInPath, parPath, inPath) => inPathSet += mainInPath
          case str:String => System.err.println(s"${str}")
          case _ => {}
        }
      }
    }catch{
      case e:Exception =>{
        System.err.println(e)
      }
    }finally {
      if(fin != null){
        fin.close()
        fin = null
      }
    }


    println("Inpath : ")
    for(inpath <- inPathSet){
      println(s"${inpath}")
    }


    println("Outpath : ")
    for(outpath <- outPathSet){
      println(s"${outpath}")
    }
  }


}
