package study;

import com.sun.javafx.binding.StringFormatter;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by saligia on 17-9-4.
 */
public class Regularly {
    public static void regularly() throws IOException {
        String mrStr = "";
        String hiveStr = "Tracking URL = http://(.*?):20888/proxy/application_(\\d{1,}_\\d{1,})/";


        System.out.println(mrStr + "|" + hiveStr);

        StringBuffer stringBuffer = new StringBuffer();
        BufferedReader readerMR = new BufferedReader(new InputStreamReader(Regularly.class.getClassLoader().getResourceAsStream("log/mapreduce.log")));

        String tmp = null;

        while((tmp = readerMR.readLine())  != null){
            stringBuffer.append(tmp);
        }
        BufferedReader readerHive = new BufferedReader(new InputStreamReader(Regularly.class.getClassLoader().getResourceAsStream("log/hive.log")));
        while((tmp = readerHive.readLine())  != null){
            stringBuffer.append(tmp);
        }

        readerHive.close();
        readerMR.close();

        Matcher matcher = Pattern.compile(mrStr + "|" + hiveStr).matcher(stringBuffer.toString());

        // System.out.println(stringBuffer.toString());

        while(matcher.find()){
            String urlFormat = "http://%s:19888/ws/v1/history/mapreduce/jobs/job_%s/conf";
            String url = "";
            if (matcher.group(1) == null) {
                url = String.format(urlFormat, matcher.group(3),matcher.group(4));
            }else{
                url = String.format(urlFormat, matcher.group(1),matcher.group(2));
                // System.out.println(matcher.group(1) + " :" + matcher.group(2));
            }

            System.out.println(url);
        }

    }
}
