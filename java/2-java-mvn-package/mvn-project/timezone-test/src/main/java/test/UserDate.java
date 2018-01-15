package test;

import io.ParseUtil;

import java.io.*;
import java.util.Properties;

/**
 * Created by saligia on 17-6-22.
 */
public class UserDate {
    public String getUsertime() throws IOException {

        InputStream modelInput = UserDate.class.getClassLoader().getResourceAsStream("output_json.model");
        String userPath = UserDate.class.getClassLoader().getResource("user_set.properties").getPath();

        Properties properties = ParseUtil.parseProperties(userPath);

        String timezone = properties.getProperty("user.timezone");

        String res = "";

        BufferedReader reader = new BufferedReader(new InputStreamReader(new BufferedInputStream(modelInput)));

        String readLine = "";

        while((readLine = reader.readLine()) !=  null){
            res += readLine;
        }
        res = res.replace("${USERTIME}", timezone);
        return res;
    }
}
