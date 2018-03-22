import java.io.InputStream;
import java.util.Properties;
import java.io.FileInputStream;
import java.util.Collection;
public class MainClass
{
  public static void main(String[] args)throws Exception
  {
    /*
    *     框架
    */
    InputStream ips = new FileInputStream("config.properties");
    Properties props = new Properties();
    //ips = this.getClass().getResourceAsStream("config.properties");   // 使用类加载器加载
    props.load(ips);
    ips.close();

    String className = props.getProperty("className");
    System.out.println(className);

    Collection collection = (Collection)Class.forName(className).newInstance();
    String one = "one";
    String two = "two";

    collection.add(one);
    collection.add(two);
    collection.add(one);

    System.out.println(collection.size());
  }
}
