package com.saligia.common;

import com.typesafe.config.Config;
import com.typesafe.config.ConfigFactory;


/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-08-29
 */
public class Propers {
    public static Propers propers = null;
    private static final String DATABASE="database";

    private final Config config;

    private Propers(){
        config = ConfigFactory.load();
    }


    public static Propers getPropers(){
        if(propers == null){
            propers = new Propers();
        }

        return propers;
    }

    public Config getDataSource() {
        return config.getConfig(DATABASE);
    }
}
