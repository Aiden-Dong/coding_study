class TestOutFor{
	public static void main(String[] args)
	{
		int b = 1;

		System.out.printf("ch = %d\n", b);
		System.out.printf("ch = %#X\n", b);
	
		//long	i = 666666666666666666;		//error
		long	i = 6666666666666666L;		// ok
		System.out.printf("i = %d\n", i);	

		//float	lf = 45.2;			// error
		float 	lf = 45.2f;			// ok
		System.out.printf("lf = %.3f\n", lf);

		char	ch = 'a';
		System.out.printf("ch = %c--%#06x\n", ch, (short)ch);
		ch = 0x0065;
		//ch = '\u0065';
		System.out.printf("ch = %c--%#06x\n", ch, (short)ch);
	
	}
}
