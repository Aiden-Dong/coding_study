class OneClass
{

  void show()
  {
    System.out.println("hello world");
  }
}
class TwoClass extends OneClass
{
  // 声明 来自show 方法不会引起重载
  /*
  @Override
  void show(String str)
  {
    System.out.println("hello saligia");
  }
  */
}

public class MainClass
{

  @SuppressWarnings("deprecation")        // 抑制警告
  public static void main(String[] args)
  {
    BaseClass one = new BaseClass();
    System.runFinalizersOnExit(true);
  }

  @Deprecated // 说明此方法已经过失
  static public void show()
  {
    System.out.println("Hello world");
  }
}
