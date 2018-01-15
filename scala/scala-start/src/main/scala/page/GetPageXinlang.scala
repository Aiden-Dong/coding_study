package page

import java.util

import scala.io.Source

/*
* @function : 获取知乎网的某个主题下面的帖子
* - 按照评论数量排序
* - 并将赞同最多的提取出来
* @url : https://www.zhihu.com/collection/62818254
* @param : page=num[1-122]
* @return : {
  [{"http://....":{
    "title"   :"page_title",
    "comment" : "num",
    "context" : "message",
    "endorse" : "num"
  }},]
* }
 */
object GetPageXinlang {

  /*
  * @func  : 根据 url 获取网页内容
  * @param : url
  * @return: 网页 html
   */
  def getMessage(url:String):String={

    val page:Source = Source.fromURL(url,"utf-8")
    var message:String = ""

    for (v_line <- page.getLines()){
      message += v_line.trim
    }
    message
  }

  /*
  *  @func  : 解析网页- 根据html信息 解析出每一个帖子的基本信息 [url,评论量,置顶评论赞同量，置顶评论url]
  *  @param : 网页 html
  *
   */
  def parseTitle(page:String, url:String):util.Map[String,TopicMsg] = {
    val titleMap:util.Map[String,TopicMsg] = new util.HashMap[String,TopicMsg]()
    // -- uri -- context--

    val titleRe = """<div class="zm-item" .*?"><h2 class="zm-item-title"><a target="_blank" href="(.*?)">(.*?)</a></h2>.*?<a class="zm-item-vote-count js-expand js-vote-count" href="javascript:;" data-bind-votecount>(\d+)</a>.*?<a href="([^"]+)" class="toggle-expand">显示全部</a>.*?<a href="#" name="addcomment" class="meta-item toggle-comment js-toggleCommentBox"><i class="z-icon-comment"></i>(\d+) 条评论</a>""".r

    for(titleRe(pageUri, pageTitle, endorse,comUri, commentNum) <- titleRe.findAllIn(page)){

      val pageUrl:String = url + pageUri               // 目的 url
      val title : String = pageTitle                   // 标题
      val comNum:Int = Integer.parseInt(commentNum)    // 评论数量
      val enNum : Int = Integer.parseInt(endorse)      // 同意数量
      val context :String = getComment(url+comUri)       // 评论内容

      val obj:TopicMsg = new TopicMsg(title, comNum, context, enNum)

      titleMap.put(pageUrl, obj);
    }

    titleMap
  }

  def getComment(url:String):String = {
    val message =""
    val contextReg = """.*?<div class="RichContent-inner"><span class="RichText CopyrightRichText-richText" itemprop="text">(.*?)</div>.*""".r
    val quoteReg = """(<.*?>)""".r
    val context = getMessage(url)

    try{
      val contextReg(titleMsg) = context

      val msg= quoteReg.replaceAllIn(titleMsg, "")
      msg
    }catch {
      case ex:scala.MatchError => ""
    }
  }

  def start():Unit={

    val urlReg = """(http[s]://[^/]+)/.*""".r

    for (index <- 1 to 122){
      val startUrl = "https://www.zhihu.com/collection/62818254?page="+index
      val urlReg(homeurl) = startUrl
      parseTitle(getMessage(startUrl), homeurl)
    }

  }
}
