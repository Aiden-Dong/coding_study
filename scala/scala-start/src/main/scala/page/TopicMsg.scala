package page

class TopicMsg(val title:String, val nComment:Int, val comMsg:String, val endorse:Int) {
  def getTitle:String = title
  def getNComment:Int = nComment
  def getComMsg:String = comMsg
  def getEndorse:Int = endorse


  override def toString = s"TopicMsg($title, $nComment, $comMsg, $endorse)"
}
