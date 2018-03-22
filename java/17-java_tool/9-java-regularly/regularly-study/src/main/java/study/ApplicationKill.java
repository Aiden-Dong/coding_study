package study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 17-11-30
 */
public class ApplicationKill {
    Pattern pattern = Pattern.compile("(application_\\d{1,}_\\d{1,})");


    public void getPattern() throws IOException {

        String applicationId = null;
        BufferedReader reader = new BufferedReader(new InputStreamReader(ApplicationKill.class.getClassLoader().getResourceAsStream("mapreduce.log")));

        String readLine = "";

        while((readLine = reader.readLine()) != null){
            Matcher matcher = pattern.matcher(readLine);

            if(matcher.find()){
                applicationId = matcher.group(1);
            }
        }

        System.out.println(applicationId);
    }
}
