package util;

import org.codehaus.jackson.JsonNode;
import org.junit.Test;

import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-2-2
 */
public class JsonTest {
    @Test
    public void testMap() throws IOException {
        Map<String, String> properties = new HashMap<String , String>();

        properties.put("name1", "value1");
        properties.put("name2", "value2");

        String json = JsonUtil.toJSON(properties,false);


        System.out.println(json);

        JsonNode jsonnode = JsonUtil.parseJSONFromString(json);


        Iterator<String> keys =  jsonnode.getFieldNames();


        while(keys.hasNext()){
            String key = keys.next();
            String value = jsonnode.get(key).asText();
            System.out.println(key + " :" + value);
        }

    }
}
