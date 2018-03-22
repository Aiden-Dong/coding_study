class FunctionMethod
{
  private int     a = 2;
  private int     b = 3;
  private String  str = "saligia";

  public String funcstr()
  {
    return "Hello world";
  }
  static public void show()
  {
    System.out.println("Hello world");
  }
  public String retustr(String str)
  {
    return str;
  }

  public void set(int a, int b, String str)
  {
    this.a = a;
    this.b = b;
    this.str = str;
  }

  public void show_variable()
  {
    System.out.println("a   = " + a);
    System.out.println("b   = " + b);
    System.out.println("str = " + str);
  }
  
  public static void main(String[] args)
  {
    for(String arg : args)
        System.out.println(arg);
    show();
  }
}
