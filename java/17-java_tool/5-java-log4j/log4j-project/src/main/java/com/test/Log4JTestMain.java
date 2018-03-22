package com.test;


import org.apache.log4j.Logger;

/**
 * Created by saligia on 17-7-10.
 */
public class Log4JTestMain {

    public static Logger logger = Logger.getLogger(Log4JTestMain.class);

    public static void main(String[] args) throws InterruptedException {

        while(true){
            logger.debug("message : debug" );
            logger.info("message : info" );
            logger.warn("message : warn");
            logger.error("message : error");
            logger.fatal("message : fatal");

            Thread.sleep(1000);
        }
    }
}
