class BaseClass
{
  public static void main(String[] args)
  {
    MainClass.show();
    // 调用已经过时的方法
    /*
    * 注: BaseClass.java使用或覆盖了已过时的 API。
    * 注: 有关详细信息, 请使用 -Xlint:deprecation 重新编译。
    */
  }
}
