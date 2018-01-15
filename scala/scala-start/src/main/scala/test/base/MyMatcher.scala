package test.base

/**
 * <pre>
 *   模式匹配和样例类
 * </pre>
 *
 * @author saligia
 * @date 17-10-3
 *
 */
object MyMatcher {

  /**
   * <pre>
   *   switch 的用法
   * </pre>
   *
   * @author saligia
   * @param None
   * @return None
   */
  def switchTest():Unit = {
    val ch:Char = '+'

    // 普通的模式匹配方式
    ch match {
      case '+' => println("Hello world +")
      case '-' => println("Hello world -")
      case _ => println("None")
    }

    //模式匹配有返回值
    val flag:Int = ch match {
      case '+' => 0
      case '-' => 1
      case _ => -1
    }
    println(flag)

    // 模式中的变量

    ch match {
      case c => println(">> " + c)
      case _=> print(">> None")
    }
  }

  /**
   * <pre>
   *   守卫功能 -- 守卫匹配功能
   * </pre>
   *
   * @author saligia
   * @param none
   * @return none
   */
  def testIfFunction():Unit={
    var char:Char = '+'
    var target:Int = 10

    target match {
      case c if (Character.isDigit(char)) => println("digit : " + c)
      case _ => println("None")
    }
  }

  /**
   * <pre>
   * </pre>
   *
   * @author saligia
   * @param obj
   * @return none
   */
  def testObj(obj:Any):Unit = {
    obj match {
      case on:Int => println("obj is int")
      case th:String => println("obj is string")
      case _ => println("other")
    }
  }

  /**
   * <pre>
   *   匹配数组，列表和元组
   * </pre>
   *
   * @author saligia
   * @param none
   * @return none
   */
  def testArray():Unit = {
    val arr:Array[String] = Array("one", "two")

    arr match {
      case Array(a,b) => println(a+":" + b)
      case _ => println("End")
    }
  }
}
