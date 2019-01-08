package com.saligia.spring.aop.aspectj;


import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

import java.lang.reflect.Method;

@Aspect
@Component
public class LogAspect {
    @Pointcut("execution(public void com.saligia.spring.aop.aspectj.Persion.say())")
    public void execPointCut(){}

    @Pointcut("within(com.saligia.spring.aop.aspectj.Persion) || args()")
    public void withPointCut(){}


    @Pointcut("@annotation(javax.jws.WebMethod)")
    public void annoPointCut(){}

    @Pointcut("args()")
    public void stringPointCut(){}

    @Around("execPointCut()")
    public void log(ProceedingJoinPoint joinPoint){
        // 方法执行前的动作
        System.out.println("Before say : ");
        try {
            // 执行目标方法
            joinPoint.proceed();
        } catch (Throwable throwable) {
            // 异常抛出之后的动作
            System.out.println("After Exception say :");
        }finally {
            // 无论是否抛出异常都执行的动作
        }
        // 正常结束后的动作
        System.out.println("After say : ");
    }
}
