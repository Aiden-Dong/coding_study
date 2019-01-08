package bean;

import com.fasterxml.jackson.annotation.JsonProperty;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-11-22
 */
public class Address {
    private String addressId;

    @JsonProperty("addressId")
    public void setAddressId(String addressId) {
        this.addressId = addressId;
    }

    @JsonProperty("addreddId")
    public String getAddressId(){
        return this.addressId;
    }

    @Override
    public String toString() {
        return addressId;
    }
}
