package com.saligia.controller;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-4-10
 */

/**
 * <pre>
 *     标识该接口全部返回Json格式
 * </pre>
 */
@RestController
@EnableAutoConfiguration
// @ResponseBody 默认自带
public class HelloWorldController {

    @RequestMapping("/index")
    public String index(){
        return "success";
    }

    @RequestMapping("/getMap")
    public Map<String, Object> getMap(){
        Map<String, Object> result = new HashMap<String, Object>();
        result.put("code", "200");
        result.put("msg", "success");
        return result;
    }

    public static void main(String[] args){
        // 主函数运行 SpringBoot 项目
        SpringApplication.run(HelloWorldController.class, args);
    }
}
