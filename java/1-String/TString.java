class TString
{
	public static void main(String args[])
	{
		// System.out.println();					将所有的值直接转化成字符串输出
		System.out.println(123);					// 123
		System.out.println(""+"one"+123);			// one123
		System.out.println("one"+123);			// one123
		System.out.println('a'+1);					// 97
		System.out.println("" + 'a'+1);			// a1

		System.out.printf(10 + ", " + 6 + "s, " + 9.7 + "\n");
	}
}
