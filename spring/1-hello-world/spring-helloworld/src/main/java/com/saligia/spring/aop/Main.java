package com.saligia.spring.aop;

public class Main {
    public static void main(String[] args) {
        Action action = new ActionInvocationHandlerImpl(new LogAction()).getAction();
        action.action();
    }
}
