package com.saligia.spring.aop.aspectj;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;

import javax.jws.WebMethod;

@Repository("persion")
public class Persion {
    public String name;

    @Value("saligia")
    public void setName(String name){
        this.name = name;
    }

    @WebMethod
    public void say(){
        System.out.println("hello : " + this);
    }

    @Override
    public String toString() {
        return name;
    }
}
