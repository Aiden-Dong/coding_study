package util

import java.io.IOException

import org.codehaus.jackson.{JsonFactory, JsonNode}
import org.codehaus.jackson.map.ObjectMapper

/** *
 * <pre>
 * </pre>
 *
 * @user : saligia
 * @date : 2018-05-28
 */
object JsonUtil {
  def toJSON(obj: Nothing, prettyPrint: Boolean): String = {
    val mapper = new ObjectMapper()
    try {
      if (prettyPrint) {
        val writer = mapper.writerWithDefaultPrettyPrinter
        return writer.writeValueAsString(obj)
      }
      mapper.writeValueAsString(obj)
    } catch {
      case e: Exception =>
        throw new IOException(e)
    }
  }

  @throws[IOException]
  def parseJSONFromString(json: String): JsonNode = {
    val mapper = new ObjectMapper()
    val factory = new JsonFactory()
    val parser = factory.createJsonParser(json)
    val node = mapper.readTree(parser)
    node
  }
}
