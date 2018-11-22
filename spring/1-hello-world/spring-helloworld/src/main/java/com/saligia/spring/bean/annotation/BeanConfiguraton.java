package com.saligia.spring.bean.annotation;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

@Configuration
@ComponentScan(basePackages = "com.saligia.spring.bean.annotation, com.saligia.spring.bean.component")
public class BeanConfiguraton {

    @Bean("persion")
    public Persion getPersion(){
        Persion persion = new Persion();
        return persion;
    }

    @Bean("address1")
    @Primary
    public Address getAddress1(){
        return new Address("address1");
    }

    @Bean("address2")
    public Address getAddress2(){
        return new Address("address2");
    }
}
