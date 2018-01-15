package test.base

import scala.io.Source
import scala.sys.process._
/**
  * Created by saligia on 17-9-21.
  */
object MyProcess {

  def getProcess():Unit={
    val process:String  = "ps -aux " !!

    val processGet = Source.fromString(process)

    for(v_line <- processGet.getLines()){
      if(v_line.split("\\s+")(0).equals("saligia")){
        println(v_line)
      }
    }
  }


}
