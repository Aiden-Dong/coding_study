package com.saligia.study.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.HashMap;
import java.util.Map;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-12-28
 */
@ResponseBody
@Controller
public class RestController {
    @GetMapping("/test")
    public Map<String, String> getTest(){
        Map<String, String> map = new HashMap<>();
        map.put("name", "saligia");
        return map;
    }
}
