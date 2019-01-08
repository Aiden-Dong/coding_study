package com.saligia.spring.aop.proxy.base;

public class RealProxySubject implements Subject {

    private Subject subject;

    public RealProxySubject(){
        this.subject = new RealSubject();
    }

    public void preRequest(){
        System.out.println("Preset Request");
    }

    public void afterRequest(){
        System.out.println("After Request");
    }

    @Override
    public void request() {
        this.preRequest();
        subject.request();
        this.afterRequest();
    }
}
