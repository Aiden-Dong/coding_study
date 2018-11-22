package com.saligia.spring.bean.xml;

import java.util.List;
import java.util.Map;
import java.util.Properties;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-11-03
 */
public class HelloWorld {
    private String name = null;
    private int value = 0;
    private Map<String, String> map = null;
    private List<String> list = null;
    private Properties properties = null;
    private Address address = null;

    public Address getAddress() {
        return address;
    }

    public void init(){
        System.out.println("start server");
    }

    public void destroy(){
        System.out.println("destroy server");
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public Properties getProperties() {
        return properties;
    }

    public void setProperties(Properties properties) {
        this.properties = properties;
    }

    public List<String> getList() {
        return list;
    }

    public void setList(List<String> list) {
        this.list = list;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getValue() {
        return value;
    }

    public Map<String, String> getMap() {
        return map;
    }

    public void setMap(Map<String, String> map) {
        this.map = map;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "HelloWorld{" +
                "name='" + name + '\'' +
                ", value=" + value +
                '}';
    }
}
