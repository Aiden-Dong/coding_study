package com.saligia.spring.aop.proxy.dynamic;

public class Main {
    public static void main(String[] args) {
        SubjectProxy proxy = new SubjectProxy(new RealSubject());
        Subject subject = proxy.getSubject();
        int result = subject.request();
        System.out.println(result);
    }
}
