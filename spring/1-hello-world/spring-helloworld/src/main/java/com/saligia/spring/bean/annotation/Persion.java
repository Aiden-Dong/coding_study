package com.saligia.spring.bean.annotation;

import com.saligia.spring.bean.component.Message;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;

public class Persion {
    private String name;
    private int value;
    private Address address;
    private Message message;

    @Value("saligia")
    public void setName(String name) {
        this.name = name;
    }

    @Value("30")
    public void setValue(int value) {
        this.value = value;
    }

    @Autowired
    public void setAddress(Address address){
        this.address = address;
    }

    @Autowired
    @Qualifier("message")
    public void setMessage(Message message){
        this.message = message;
    }

    @Override
    public String toString() {
        return "Persion{" +
                "name='" + name + '\'' +
                ", value=" + value +
                ", address=" + address +
                ", message=" + message +
                '}';
    }
}
