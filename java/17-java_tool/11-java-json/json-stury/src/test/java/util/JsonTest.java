package util;

import bean.Persion;
import com.fasterxml.jackson.databind.JsonNode;
import org.junit.Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;
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
    public void testJsonNode() throws IOException {
        String str = "[\"test1\", \"test2\", \"test3\"]";
        Object node = JsonUtil.json2Object(str);
        System.out.println(node.toString());
    }

    @Test
    public void testMapBean() throws IOException {
        String str = "{\n" +
                "  \"name\" : \"test\",\n" +
                "  \"value\" : 20,\n" +
                "  \"address\" : [\n" +
                "    {\n" +
                "     \"addressId\" : \"0001\" \n" +
                "    },\n" +
                "    {\n" +
                "    \"addressId\" : \"0002\"\n" +
                "    }\n" +
                "  ]\n" +
                "}";

        Map map = (Map) JsonUtil.json2Object(str);
        System.out.println(map.get("address"));
        List<Map<String, String>> list = (List<Map<String, String>>)map.get("address");
        System.out.println(list.get(1).get("addressId"));


        String value = JsonUtil.object2Str(map, true);
        System.out.println(value);
    }

    @Test
    public void testBean() throws IOException {
        String str = "{\n" +
                "  \"v-name\" : \"test\",\n" +
                "  \"v-value\" : 20,\n" +
                "  \"address\" : [\n" +
                "    {\n" +
                "     \"addressId\" : \"0001\" \n" +
                "    },\n" +
                "    {\n" +
                "    \"addressId\" : \"0002\"\n" +
                "    }\n" +
                "  ]\n" +
                "}";

        Persion persion = JsonUtil.str2Bean(str, Persion.class);

        String value = JsonUtil.object2Str(persion, true);
        System.out.println(value);
    }
}
