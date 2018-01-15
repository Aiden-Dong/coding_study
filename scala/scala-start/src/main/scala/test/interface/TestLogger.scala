package test.interface

/**
  * Created by saligia on 17-9-21.
  */
trait TestLogger {
  def loggers(msg:String): Unit ={
    println("test "  + msg + " ++++")
  }
}
