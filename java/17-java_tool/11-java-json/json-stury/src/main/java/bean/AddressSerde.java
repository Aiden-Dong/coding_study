package bean;

import com.fasterxml.jackson.core.JsonGenerator;
import com.fasterxml.jackson.databind.JsonSerializer;
import com.fasterxml.jackson.databind.SerializerProvider;

import java.io.IOException;
import java.util.List;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-11-22
 */
public class AddressSerde extends JsonSerializer<List<Address>> {
    @Override
    public void serialize(List<Address> addresses, JsonGenerator jsonGenerator, SerializerProvider serializerProvider) throws IOException {

        jsonGenerator.writeStartArray();
        for(Address address : addresses){
            jsonGenerator.writeObject(address);
        }
        jsonGenerator.writeEndArray();


    }
}
