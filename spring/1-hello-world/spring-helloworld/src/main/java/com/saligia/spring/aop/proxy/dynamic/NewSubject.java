package com.saligia.spring.aop.proxy.dynamic;

public class NewSubject implements Subject {

    public NewSubject() {
        System.out.println("New Subject");
    }

    @Override
    public int request() {
        System.out.println("test");
        return 10;
    }
}
