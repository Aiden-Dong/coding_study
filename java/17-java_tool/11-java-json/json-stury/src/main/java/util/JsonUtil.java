package util;



import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.ObjectWriter;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.util.List;
import java.util.Map;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-2-2
 */
public class JsonUtil {

    /**
     * <pre>
     *     文件字符串解析
     * </pre>
     */
    public static JsonNode str2JsonNode(String str) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readTree(str);
    }

    /**
     * <pre>
     *     stream 解析
     * </pre>
     */
    public static JsonNode str2JsonNode(InputStream stream) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readTree(stream);
    }
    /**
     * <pre>
     *     file 解析
     * </pre>
     */
    public static JsonNode str2JsonNode(File file) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readTree(file);
    }

    /**
     * <pre>
     *     reader 解析
     * </pre>
     */
    public static JsonNode str2JsonNode(Reader reader) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readTree(reader);
    }

    /**
     * <pre>
     *     bytes 解析
     * </pre>
     */
    public static JsonNode str2JsonNode(byte[] datas) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readTree(datas);
    }

    /**
     * <pre>
     * </pre>
     * */
    public static Object json2Object(String str) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        JsonNode node = objectMapper.readTree(str);
        if(node.isObject()){
            return objectMapper.readValue(str, Map.class);
        }else if(node.isArray()){
            return objectMapper.readValue(str, List.class);
        }else{
            if (node.isInt()) {
                return node.asInt();
            } else if (node.isLong()) {
                return node.asLong();
            } else if (node.isDouble()) {
                return node.asDouble();
            } else if(node.isTextual()) {
                return node.asText();
            } else if (node.isNull()){
                return null;
            }
            else {
                throw new IOException("Json node exception type :  " + node.numberType());
            }
        }
    }

    public static String object2Str(Object object, boolean prettyPrint) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();

        // 美化方式打印
        if(prettyPrint){
            ObjectWriter write = objectMapper.writerWithDefaultPrettyPrinter();
            return write.writeValueAsString(object);
        }
        // 单行打印
        return objectMapper.writeValueAsString(object);
    }

    public static <T> T str2Bean(String str, Class<T> beanClass) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        return mapper.readValue(str, beanClass);
    }

   }
