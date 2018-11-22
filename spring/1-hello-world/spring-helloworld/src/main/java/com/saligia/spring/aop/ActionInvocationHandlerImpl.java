package com.saligia.spring.aop;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

/**
 * <pre>
 *     自定义代理实现类
 * </pre>
 */
public class ActionInvocationHandlerImpl implements InvocationHandler {
    private Object action;

    public ActionInvocationHandlerImpl(Object action)
    {
        this.action = action;
    }


    public Action getAction(){
        return (Action) Proxy.newProxyInstance(action.getClass().getClassLoader(),
                action.getClass().getInterfaces(),
                this);

    }
    /**
     * <pre>
     *     动态代理具体的实现类
     * </pre>
     *
     * @param proxy 具体的代理对象
     * @param method 当前调用的方法
     * @param args 调用参数
     */
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {

        System.out.println("Before action");
        Object value = method.invoke(action, args);
        System.out.println("End action");

        return value;
    }
}
