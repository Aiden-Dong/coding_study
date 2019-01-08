package com.saligia.spring.aop.aspectj;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("com/saligia/spring/aop/aspectj/aspectJ.xml");
        Persion persion = (Persion)context.getBean("persion");
        persion.say();
    }
}
