package test.base

import scala.io.Source

/**
  * Created by saligia on 17-9-20.
  */
object SourceObj {
  // fileGetdataplatform

  // 遍历文件
  def getFileContext():Unit = {

     val file = Source.fromFile("/home/saligia/tmp/passwd")

    for (v_line <- file.getLines()){
      println(v_line)
    }
  }
  // 打印成一行
  def getFileContextOnline():Unit = {
    val file = Source.fromFile("/home/saligia/tmp/task.json")

    println(file.mkString)
  }
  // 字符遍历
  def getFileChar():Unit = {
    var file = Source.fromFile("/home/saligia/tmp/task.json")

    for(v_char <- file if !v_char.equals(' ') && !v_char.equals('\n')){
      print(v_char)
    }
  }

  // 查看字符

  def watchContext():Unit={

    val file = Source.fromFile("/home/saligia/tmp/task.json")
    val iter = file.buffered

    while(iter.hasNext){
      if(!iter.head.equals(' ') && !iter.head.equals('\n')){
        print(iter.next())
      }else{
        iter.next()
      }
    }

  }

  // 网页摘取
  def getUrlMessage():Unit={
    val message = Source.fromURL("https://www.zhihu.com/explore")

    var pageMessage = ""
    for(v_line <- message.getLines()){
      pageMessage = pageMessage + v_line
    }

    val pngReg = """<a class="question_link".*?>(.*?)</a>""".r

    for(pngReg(context) <- pngReg.findAllIn(pageMessage)){
      println(context)
    }
  }
}
