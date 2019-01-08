package com.saligia.spring.mvc.start.mvc;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {
    @GetMapping("/")
    public String hello(Model model){
        model.addAttribute("message", "Hello Spring MVC 5!");
        return "index";
    }
}
