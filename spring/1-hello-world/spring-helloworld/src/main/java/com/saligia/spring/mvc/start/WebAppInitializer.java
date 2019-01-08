package com.saligia.spring.mvc.start;

import org.springframework.web.servlet.support.AbstractAnnotationConfigDispatcherServletInitializer;

public class WebAppInitializer extends AbstractAnnotationConfigDispatcherServletInitializer {

    static {
        System.out.println("hello world");
    }

    /**
     * <pre>
     *     应用上下文， 除Web的部分
     * </pre>
     */
    @Override
    protected Class<?>[] getRootConfigClasses() {
        return null;
    }

    /**
     * <pre>
     *     web 应用上下文
     * </pre>
     */
    @Override
    protected Class<?>[] getServletConfigClasses() {
        return new Class[]{WebConfig.class};
    }

    /**
     * <pre>
     *     DispatcherServlet 的映射路径
     * </pre>
     */
    @Override
    protected String[] getServletMappings() {
        return new String[]{"/"};
    }

}
