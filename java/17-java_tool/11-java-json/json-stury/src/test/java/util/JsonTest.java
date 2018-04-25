package util;

import org.codehaus.jackson.JsonNode;
import org.junit.Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

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
        BufferedReader reader = new BufferedReader(new FileReader(new File("/home/saligia/github/coding_study/java/17-java_tool/11-java-json/json-stury/src/test/resources/test.json")));

        StringBuffer buffer = new StringBuffer();

        String sLine = "";

        while((sLine = reader.readLine()) != null){
            buffer.append(sLine);
        }
        reader.close();

        JsonNode node = JsonUtil.parseJSONFromString(buffer.toString());


        for(JsonNode property : node.get("conf").get("property")){
            if(property.get("name").asText().equals("mapreduce.input.fileinputformat.inputdir")){
                System.out.println(property.get("value").asText());
            }
        }


    }
}
