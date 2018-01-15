package test.interface

/**
  * Created by saligia on 17-9-21.
  */
trait Logger {
  def logger(msg:String): Unit ={
    println("++++ "  + msg + " ++++")
  }
}
