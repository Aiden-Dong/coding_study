package test.interface

/**
  * Created by saligia on 17-9-21.
  */
trait DateLogger extends Logger{
  override def logger(msg: String): Unit = {
    super.logger("---" + msg + "---")
  }
}
