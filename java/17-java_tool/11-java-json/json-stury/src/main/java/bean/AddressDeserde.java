package bean;

import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.DeserializationContext;
import com.fasterxml.jackson.databind.JsonDeserializer;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.google.common.collect.Lists;
import util.JsonUtil;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-11-22
 */
public class AddressDeserde extends JsonDeserializer<List> {
    public List deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
        ObjectMapper mapper = new ObjectMapper();
        JsonNode nodes = mapper.readTree(jsonParser);

        List<Address> addresses = new LinkedList<Address>();

        for(JsonNode node :  Lists.newArrayList(nodes.elements())){
            addresses.add(JsonUtil.str2Bean(node.toString(), Address.class));
        }
        return addresses;
    }
}
