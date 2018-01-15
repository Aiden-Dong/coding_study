package test;

import org.joda.time.DateTime;
import org.junit.Test;
import static org.junit.Assert.*;

import java.io.IOException;
import java.time.DateTimeException;

/**
 * Created by saligia on 17-6-22.
 */
public class TestUserDate {
    @Test
    public void testGetUserTime() throws IOException {
        UserDate date = new UserDate();
        System.out.println(date.getUsertime());

        assertEquals("{\"user.timezone\":\"UTC\"}",date.getUsertime());


    }
}
