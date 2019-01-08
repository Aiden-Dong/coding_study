package com.saligia.spring.aop.proxy.base;

public class RealSubject implements Subject{

    @Override
    public void request() {
        System.out.println("request");
    }
}
