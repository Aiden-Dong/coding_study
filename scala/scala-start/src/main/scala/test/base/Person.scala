package test.base

/**
  * Created by saligia on 17-9-19.
  */
object Person{
  def apply(name:String, age:Int): Person = new Person(name, age)
}

class Person(private var name:String, private var age:Int)extends AbPerson{

  override def getName():String = name

  override def setName(name:String):Unit = {
    this.name = name
  }

  def getAge():Int = age

  def setAge(age:Int):Unit = {
    this.age = age
  }

  override def toString:String ={
    "name=" + this.name+"\nage="+this.age
  }
}
