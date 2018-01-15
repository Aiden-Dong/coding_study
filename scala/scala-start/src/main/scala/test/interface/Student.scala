package test.interface

/**
  * Created by saligia on 17-9-21.
  */
class Student (var name :String) extends Persion{

  override def getName(): String = this.name
  override def setName(name: String): Unit = {
    this.name = name
  }
  override def getMessage(): String = {
    return "name : " + this.name
  }

  def update(name:String,value:String):Unit = {
    println(name+ ":" + value)
  }

  def apply(name: String): Unit={
    println("name : " + name)
  }
}
