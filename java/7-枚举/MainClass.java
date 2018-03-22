/*
*		 枚举型变量的使用
*               -> String toString();  返回枚举常量的名称，它包含在声明中。
*               -> int	ordinal();     返回枚举常量的序数（它在枚举声明中的位置，其中初始常量序数为零）。
*               -> WeekDay[] values(); 返回枚举型的数组
*/

public class MainClass
{
	enum WeekDay{Monday, Tuesday, Wednsday, Thursday, Friday, Satursday, Sunday}

	// 可以实现该枚举的方法 
	public enum TrafficLamp
	{
		READ
		{
					public TrafficLamp nextLamp()
					{
						return GREEN;
					}

		},
		GREEN
		{
					public TrafficLamp nextLamp()
					{
						return YELLOW;
					}
		},
		YELLOW
		{
			public TrafficLamp nextLamp()
			{
				return  READ;
			}
		};

		public abstract TrafficLamp nextLamp();			// 枚举类内部的抽象类
	}

	public static void main(String[] args)
	{
		WeekDay one = WeekDay.Monday;
		System.out.println(one.toString());			  // 调用 toString 方法
		System.out.println(one.ordinal());            // 返回枚举的序号

        for(WeekDay show : WeekDay.values())                      // 查看所有的枚举类型
        {
            System.out.printf(show.toString() + " ");
        }
        System.out.printf("\n");
    }
}
