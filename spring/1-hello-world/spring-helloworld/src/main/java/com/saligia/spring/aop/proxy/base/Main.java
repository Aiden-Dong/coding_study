package com.saligia.spring.aop.proxy.base;

public class Main {
    public static void main(String[] args) {
        Subject subject = new RealProxySubject();
        subject.request();
    }
}
