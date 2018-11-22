package com.saligia.spring.bean;

import com.saligia.spring.bean.annotation.Persion;
import com.saligia.spring.bean.xml.HelloWorld;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-11-03
 */
public class Main {
    public static void main(String[] args) {
        ApplicationContext ioc = new ClassPathXmlApplicationContext("com/saligia/spring/bean/annotation/hello-world.xml");
        Persion persion = (Persion)ioc.getBean("persion");
        System.out.println(persion);
        ((ClassPathXmlApplicationContext) ioc).close();
    }
}
