package com.saligia.spring.aop.proxy.dynamic;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class SubjectProxy implements InvocationHandler {

    private Subject subject;

    public SubjectProxy(Subject subject) {
        this.subject = subject;
    }

    public Subject getSubject(){
        return (Subject) Proxy.newProxyInstance(subject.getClass().getClassLoader(), subject.getClass().getInterfaces(), this);
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        System.out.println("Preset Action");
        Object result= method.invoke(subject, args);
        System.out.println("After Action");
        return result;
    }
}
