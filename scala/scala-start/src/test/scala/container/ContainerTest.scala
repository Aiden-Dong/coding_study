package container

import org.junit.Test

import scala.collection.mutable

/** *
 * <pre>
 *   测试容器的相关特性
 * </pre>
 *
 * @user : saligia
 * @date : 2018-06-06
 */
class ContainerTest {
  @Test
  def testHashSet():Unit = {

    var setA = mutable.HashSet[String]()
    val setB = mutable.HashSet[String]("a", "b", "c")

    // 并集测试
    setA = setA.union(setB)

    for(item <- setA){
      println(item)
    }
  }
}
