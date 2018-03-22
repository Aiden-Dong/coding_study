package io;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

/**
 * Created by saligia on 17-6-22.
 */
public class ParseUtil {
    public static Properties parseProperties(String path) throws IOException {
        Properties properties = new Properties();
        FileInputStream fin = new FileInputStream(path);
        properties.load(fin);
        return properties;
    }
}
