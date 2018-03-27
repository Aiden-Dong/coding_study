package time;

import org.joda.time.DateTime;
import org.joda.time.DateTimeZone;
import org.joda.time.format.DateTimeFormat;
import org.joda.time.format.DateTimeFormatter;
import org.joda.time.format.ISODateTimeFormat;
import org.junit.Test;

import java.text.DateFormat;

/**
 * Created by saligia on 17-7-20.
 */
public class DateTimeGetTest {

    /**
     * <pre>
     *      DateTimeZone: 设置时间的时区类
     *          -- forID: 得到时区的实例对象
     *          -- setDefault(DateTimeZone) : 设置默认的DateTime时区
     *      DateTime:
     *          -- withZone(DateTimeZone)　: 返回这个时间在不同时区的对应时间的副本(保留毫秒数:2018-03-27T11:44:28.435+08:00/2018-03-27T03:44:28.435Z)
     *          -- withZoneRetainFields(DateTimeZone) : : 返回这个时间在不同时区的对应时间的副本(保留字段:2018-03-27T11:44:28.435+08:00/2018-03-27T11:46:43.941Z)
     * </pre>
     *
     * @author
     * @param
     * @return
     */
    //@Test
    public void testTimeInZone(){
        //System.setProperty("user.timezone", "UTC");
        //System.out.println("===");
        //System.out.println(System.getProperty("user.timezone"));


        //DateTimeZone zone = DateTimeZone.forID("+0800");
        //System.out.println(zone.getID());
        DateTime dateTime = DateTime.now();
        DateTime newTime = dateTime.withZone(DateTimeZone.UTC);
        DateTime newTime2 = dateTime.withZoneRetainFields(DateTimeZone.UTC);

        System.out.println(ISODateTimeFormat.dateTime().print(dateTime));
        System.out.println(ISODateTimeFormat.dateTime().print(newTime));
        System.out.println(ISODateTimeFormat.dateTime().print(newTime2));

        //DateTime time = DateTime.parse("2017-09-01", DateTimeFormat.forPattern("yyyy-MM-dd"));
        //time  = time.withZone(DateTimeZone.UTC);
        //out.println(time);
    }

    /**
     * <pre>
     *     ISODateTimeFormat : 用户返回格式化字符串或者将字符串反格式化的工具，它返回的是一个DateTimeFormatter.
     *          -- dateTime(): 'yyyy-MM-dd'T'HH:mm:ss.SSSZZ'
     *     DateTime:
     *             -- now() : 返回当前时间的静态方法
     *             -- withTimeAtStartOfDay() : 返回当前时间的所在时区所在日期的开始时间(时间截止到:yyyy-mm-ddT00:00:00).
     * </pre>
     *
     * @author　saligia
     */
    //@Test
    public void testIsoTime(){
        DateTime dateTime = DateTime.now().withTimeAtStartOfDay();

        System.out.println(ISODateTimeFormat.dateTime().print(dateTime));
    }
    @Test
    public void testTimePeriod(){
        //DateTimeGet.timePeriod();
    }


    @Test
    public void testTimeTimestamp(){
        DateTime dateTime = DateTime.now();

    }

    @Test
    public void testTruncTime(){
        //DateTimeGet.truncTime();
    }

}
