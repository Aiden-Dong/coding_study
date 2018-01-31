package time;

import org.joda.time.DateTime;
import org.joda.time.DateTimeZone;
import org.joda.time.format.DateTimeFormat;
import org.joda.time.format.DateTimeFormatter;
import org.junit.Test;

import java.text.DateFormat;

/**
 * Created by saligia on 17-7-20.
 */
public class DateTimeGetTest {
    @Test
    public void testTimeInZone(){
        DateTime time = DateTime.parse("20150912T000000.000Z",DateTimeFormat.forPattern("yyyyMMdd'T'HHmmss.SSSZ"));

        //DateTime time =  new DateTime();
        System.out.println(time.toString());
    }

    @Test
    public void testIsoTime(){
        //DateTimeGet.isoTime();
    }
    @Test
    public void testTimePeriod(){
        //DateTimeGet.timePeriod();
    }


    @Test
    public void testTimeTimestamp(){
        //DateTimeGet.timeTimestame();
    }

    @Test
    public void testTruncTime(){
        //DateTimeGet.truncTime();
    }

}
