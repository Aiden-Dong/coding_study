package test.base


import org.codehaus.jackson.{JsonFactory, JsonNode, JsonParser}
import org.codehaus.jackson.map.ObjectMapper

/**
  * <pre>
  * </pre>
  *
  * @author saligia
  * @date 17-9-26
  */
object UtilParse {

/**
 *<pre>
  *   String 转json
 *</pre>
 *
 *@author saligia
 *@param null
 *@return jsonNode
 */
  def stringToJson(str:String):JsonNode = {
    val mapper:ObjectMapper = new ObjectMapper()
    val factory:JsonFactory = new JsonFactory()
    val jsonParse:JsonParser = factory.createJsonParser(str)

    val node:JsonNode = mapper.readTree(jsonParse)

    node
  }


  /**
   *<pre>
    *   object to json string
   *</pre>
   *
   *@author saligia
   *@param null
   *@return jsonNode
   */
  def objectToJson(obj :AnyRef):String = {
    val mapper:ObjectMapper = new ObjectMapper()
    return mapper.writeValueAsString(obj)
  }

}
