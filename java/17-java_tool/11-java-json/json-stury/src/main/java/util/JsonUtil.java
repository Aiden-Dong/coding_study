package util;

import org.codehaus.jackson.JsonFactory;
import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.JsonParser;
import org.codehaus.jackson.map.ObjectMapper;
import org.codehaus.jackson.map.ObjectWriter;

import java.io.IOException;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-2-2
 */
public class JsonUtil {

    public static String toJSON(Object obj, boolean prettyPrint) {
        ObjectMapper mapper = new ObjectMapper();

        try {
            if (prettyPrint) {
                ObjectWriter writer = mapper.writerWithDefaultPrettyPrinter();
                return writer.writeValueAsString(obj);
            }
            return mapper.writeValueAsString(obj);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static JsonNode parseJSONFromString(String json) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        JsonFactory factory = new JsonFactory();
        JsonParser parser = factory.createJsonParser(json);
        JsonNode node = mapper.readTree(parser);
        return node;
    }
}
