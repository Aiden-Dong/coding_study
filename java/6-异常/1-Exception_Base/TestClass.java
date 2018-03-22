/*
*	异常情况 ------------------ 运行时错误
*		-> 	使用 try -- catch 机制捕获错误机制
*/

class BaseClass
{
	public int divide(int a, int b)
	{
		int m;
		m = a/b;
		System.out.printf("val = %d\n", m);
        // 发生异常后， 此处不会被执行， 直接出栈 转 --- try
		return m;
	}
}

class MainClass
{
	public static void main(String args[])
	{
		int val = 1;

		BaseClass one = new BaseClass();
		
		// 捕获被抛出的异常
		try{
			val = one.divide(4, 0);
            // 异常之后， 此处不会被赋值，及调用无效， 转 catch 
		}
		// 发生异常的处理
        // errno        代表捕获的异常
        // Exception    代表异常的类型
		catch(Exception errno)
		{
			errno.printStackTrace();
			System.out.printf("获取错误\n");
		}

		System.out.printf("hello world : %d\n",  val);
	}
}
