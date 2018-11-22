package bean;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
import sun.jvm.hotspot.debugger.Address;

import java.util.List;
import java.util.Map;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-11-22
 */

@JsonIgnoreProperties(ignoreUnknown = true)
public class Persion {
    private String name;
    private int value;
    private List<Address> address;

    @JsonProperty("v-name")
    public void setName(String name) {
        this.name = name;
    }

    @JsonProperty("v-value")
    public void setValue(int value) {
        this.value = value;
    }


    @JsonProperty("address")
    @JsonDeserialize(using = bean.AddressDeserde.class)
    public void setAddress(List<Address> address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Persion{" +
                "name='" + name + '\'' +
                ", value=" + value +
                ", addresses=" + address +
                '}';
    }
}
