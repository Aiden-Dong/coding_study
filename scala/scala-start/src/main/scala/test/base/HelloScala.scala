package test.base


import scala.collection.immutable.HashMap
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

/**
  * Created by saligia on 17-9-5.
  */
object HelloScala {

  def main(args: Array[String]): Unit = {
    System.out.println("hello world")
  }
  def sum(num:Int, baseValue:Int=1):Int = {
    var sum = 0
    for (i <- 1 to num){
      sum += i
    }
    sum/baseValue
  }

  def dataGet(datas:Any*):Unit = {
    for (data <- datas){
      if(data.isInstanceOf[String]){
        println("String")
      }else if(data.isInstanceOf[Int]){
        println("Int")
      }else if(data.isInstanceOf[Double]){
        println("double")
      }else if(data.isInstanceOf[Byte]){
        println("Byte")
      }else{
        println("Other")
      }
    }
  }

  def testException():Unit = {
    throw new IllegalArgumentException("hello")
  }

  def showArry(arr:Array[Int]): Unit ={
    for(elem <- arr){
      print(elem + " ")
    }
    println();
  }

  def startEnum():Unit = {
    // 创建一个枚举
    val enum = EnumType.Green

    println(enum)
  }

  def startExtend():Unit = {
    val student = new Person("one", 20){
      def getMessage() :Unit = {
        println(this.toString)
      }
    }

    student.getMessage()
  }

  // 数组测试
  def arrayGet():Unit = {
    // 定长数组
    val arr:Array[Int] = new Array[Int](10)             // 声明长度为10, 初始化为0的整形数组．
    val names:Array[String] = Array("test1", "test2")   // 长度为２　初始化完成的数组

    for(i <- 0 until arr.length){
      if(i < 2){
        arr(i) = 1
      }else{
        arr(i) = arr(i-1) + arr(i-2)
      }
    }
    showArry(arr)
    println(names(1))

    // 变长数组
    val numArr:ArrayBuffer[Int] = new ArrayBuffer[Int]();

    for(i <- 0 to 10){
      if(numArr.length < 2){
        numArr.append(1)
      }else{
        val num:Int = numArr(numArr.length-1) + numArr(numArr.length-2)

        numArr.append(num)
      }
    }

    showArry(numArr.toArray)

    // 多维数组
    val dimArr = Array.ofDim[Int](2,3)  // 创建一个2行，3列的数组
  }

  // 映射
  def mapGet():Unit = {
    /*
    * 值不可变
     */
    val testMap:Map[String, Int] = Map("Alice"-> 1, "Test" -> 2, "Get"-> 3)
    /*
    * 值可以修改
     */
    val testMapTest : scala.collection.mutable.Map[String,Int] = scala.collection.mutable.Map("Alice"->1, "Test" -> 2, "Get" -> 3)
    val hashMap:HashMap[String, Int] = new HashMap[String, Int]()
    var treeMap:mutable.TreeMap[String, Int] = new mutable.TreeMap[String, Int]()

    treeMap += ("Alice" -> 1)

    println(treeMap("Alice"))
    val value = if(testMap.contains("Test")) testMap("Test") else 0
    val valus = testMap.getOrElse("Test", 0)

  }

  // 元組
  def tupleGet() : Unit = {
    val tupleTest = (1, 3.22, "hello world")

    val (v_num, v_double, v_str) = tupleTest  // 批量赋值

    println(v_num)
    println(v_double)
    println(v_str)

    val(_, _, strLne) = tupleTest  // 给某个值赋值　
    println(strLne)

    val keyArray:Array[String] = Array("one", "two", "three")
    val valueArray:Array[Int] = Array(1, 2, 3)

    val mapArray = keyArray.zip(valueArray)

    for(one <- mapArray){
      println(one._1 + ":" + one._2)
    }
    println(mapArray.toMap)
  }

  def start(): Unit = {
    MyIterab.getStack()
  }
}