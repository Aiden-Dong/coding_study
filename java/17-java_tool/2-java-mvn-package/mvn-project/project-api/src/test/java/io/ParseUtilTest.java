package io;

import org.joda.time.DateTime;
import org.junit.Test;

import java.io.IOException;
import java.util.Properties;
import static org.junit.Assert.*;

/**
 * Created by saligia on 17-6-22.
 */
public class ParseUtilTest {

    @Test
    public void testParseProperties() throws IOException {
        String path = ParseUtilTest.class.getClassLoader().getResource("test.properties").getPath();
        Properties properties = ParseUtil.parseProperties(path);

        System.out.println(properties.getProperty("user.timezone"));

        System.setProperty("user.timezone",properties.getProperty("user.timezone"));
        DateTime dateTime = new DateTime();

        System.out.println(dateTime.toString("yyyy-MM-dd HH:mm:ss zzz"));

        assertEquals("UTC", properties.getProperty("user.timezone"));
    }
}
