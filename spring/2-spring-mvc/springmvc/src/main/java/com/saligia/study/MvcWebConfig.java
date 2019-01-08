package com.saligia.study;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.ViewResolverRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurationSupport;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;
import org.thymeleaf.spring5.SpringTemplateEngine;
import org.thymeleaf.spring5.templateresolver.SpringResourceTemplateResolver;
import org.thymeleaf.spring5.view.ThymeleafViewResolver;

@Configuration
@ComponentScan("com.saligia.study.controller")
public class MvcWebConfig extends WebMvcConfigurationSupport {

    // org.springframework.web.servlet.HandlerMapping : org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerMapping
    // org.springframework.web.servlet.HandlerAdapter : org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerAdapter



    @Autowired
    private ApplicationContext applicationContext;


    // <!-- Thymeleaf 视图 -->
    /**
     * <pre>
     *     视图解析器
     * </pre>
     */
    @Bean
    public SpringResourceTemplateResolver templateResolver() {
        SpringResourceTemplateResolver templateResolver = new SpringResourceTemplateResolver();
        templateResolver.setCharacterEncoding("UTF-8");
        templateResolver.setApplicationContext(applicationContext);
        templateResolver.setPrefix("classpath:/webapp/");
        templateResolver.setSuffix(".html");
        return templateResolver;
    }

    /**
     * <pre>
     *   视图解析引擎
     * </pre>
     */
    @Bean
    public SpringTemplateEngine templateEngine() {
        SpringTemplateEngine templateEngine = new SpringTemplateEngine();
        templateEngine.setTemplateResolver(templateResolver());
        templateEngine.setEnableSpringELCompiler(true);

        return templateEngine;
    }

    /*
     * 配置 Thymeleaf
     * */
    @Override
    public void configureViewResolvers(ViewResolverRegistry registry) {
        ThymeleafViewResolver resolver = new ThymeleafViewResolver();
        resolver.setTemplateEngine(templateEngine());
        registry.viewResolver(resolver);
    }

}
