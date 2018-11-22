package com.saligia.spring.bean.component;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

@Component("message")
public class Message {
    private String message ;

    @PostConstruct
    public void postConstruct(){
        System.out.println("init Message");
    }

    @Value("testMessage")
    public void setMessage(String message) {
        this.message = message;
    }

    @PreDestroy
    public void destroy(){
        System.out.println("destroy Message");
    }


    @Override
    public String toString() {
        return message;
    }
}
