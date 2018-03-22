class A{
	int i;
	int j;
}

class TestMemo{
	public static void main(String args[])
	{
		A bb = new A();	
		A aa = new A();
			// new A() : 	在堆中动态分配一块区域， 被当作了 A 对象
			// aa 	  	本身内存是在栈中分配的
			// 		堆中内存的地址付给了 aa
			// aa 	   	指向了堆中的内存， aa 代表了堆中的内存
			// aa.i 	代表的是 aa 这个静态指针变量所指向的动态内存中的 A 对象

		aa.i	= 10;
		aa.j	= 20;
		bb.i 	= 23;
		bb.j	= 34;

		System.out.printf("i = %d\n", aa.i);
		System.out.printf("j = %d\n", aa.j);
		System.out.printf("i = %d\n", bb.i);
		System.out.printf("j = %d\n", bb.j);
	}
}
