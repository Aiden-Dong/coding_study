package com.saligia.spring.mvc.start.mvc;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.HashMap;
import java.util.Map;

//@Controller
//@ResponseBody
public class TestController {

    @GetMapping("/test")
    public Map<String, String> test(){
        Map<String, String> map = new HashMap<String, String>();
        map.put("name", "saligia");
        return map;
    }
}
