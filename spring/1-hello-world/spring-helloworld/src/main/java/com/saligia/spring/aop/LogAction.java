package com.saligia.spring.aop;

/**
 * <pre>
 *     被代理对象
 * </pre>
 */
public class LogAction implements Action{
    public int action(){
        System.out.println("action");
        return 20;
    }
}
