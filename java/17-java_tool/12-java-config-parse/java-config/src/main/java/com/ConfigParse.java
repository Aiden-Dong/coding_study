package com;

import com.typesafe.config.Config;
import com.typesafe.config.ConfigFactory;
import com.typesafe.config.ConfigValue;

import java.util.Map;


/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-4-3
 */
public class ConfigParse {
    public static void parseConfig(){

        /**
         * 方法 ConfigFactory.load() 属性加载来源:
         * system properties
         * application.conf (all resources on classpath with this name)
         * application.json (all resources on classpath with this name)
         * application.properties (all resources on classpath with this name)
         * reference.conf (all resources on classpath with this name)
         */
        Config config = ConfigFactory.load();

        // 获取单个元素的值
        String azkbanOffUrl = config.getString("azkaban-offline.mysql.url");
        System.out.println(azkbanOffUrl);

        /**
         * 包含用户自定义属性:
         *  -- 用户自定义属性如: azkaban-offline.azkaban.userName
         *  -- 系统环境属性如　: sun.jnu.encoding
         */
        for(Map.Entry<String, ConfigValue> entry : config.entrySet()){
            System.out.println(">>> " + entry.getKey());
        }


        /**
         * 获取配置子集
         */
        Config configNode = config.getConfig("kafka");
    }
}
