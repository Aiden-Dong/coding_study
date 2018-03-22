import java.util.concurrent.*;
import java.util.ArrayList;

class TestJob implements Callable<String>
{
  private int id;
  public TestJob(int id)
  {
    this.id = id;
  }
  public String call()
  {
    return "result of : " + id;
  }
}

public class MyCallable
{
  public static void main(String[] args)
  {
    ExecutorService exec = Executors.newCachedThreadPool();
    ArrayList<Future<String>> result = new ArrayList<Future<String>>();

    for(int i = 0; i < 5; i++)
      result.add(exec.submit(new TestJob(i)));

    for(Future<String> one : result)
    {
      try{
        System.out.println(one.get());        // 获取任务的返回值
      }catch(Exception e){
        e.printStackTrace();
      }finally{
        exec.shutdown();
      }

    }

  }
}
