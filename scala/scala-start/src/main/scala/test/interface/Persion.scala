package test.interface

/*
 * @author saligia
 * @doc   test
 */
trait Persion {
  /*
   * @author saligia
   * @return persionName
   */
  def getName():String
  /*
   * @param name
   * @return Unit
   */
  def setName(name:String):Unit

  /*
  * @doc get persion message
   */
  def getMessage():String
}
