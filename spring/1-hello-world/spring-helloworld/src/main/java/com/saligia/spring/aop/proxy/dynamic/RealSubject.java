package com.saligia.spring.aop.proxy.dynamic;

public class RealSubject implements Subject{
    @Override
    public int request() {
        System.out.println("hello world");
        return 10;
    }
}
