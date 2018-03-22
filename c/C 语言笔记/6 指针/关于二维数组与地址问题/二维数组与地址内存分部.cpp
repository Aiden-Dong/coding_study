# include <stdio.h>

int main (void)
{
	int i , j;
	int l[2][3] = {
		{1 , 2 , 3},
		{4 , 5 , 6}
	};

	 for (i = 0; i <= 1 ;i ++)
	 {
		 for ( j = 0 ; j <= 2; j++)
			 printf ("%d  ",&l[i][j]);
		 printf ("\n");
	 }
	  printf ("\n");
	 for (i = 0 ; i <= 1 ; i ++)
		printf ("l[%d] = %d\n", i ,  &l[i]);
	 printf ("\n");
	 printf ("l = %d\n",&l);

}
/*
在 VC++ 6.0 中的输出结果是 ：
====================================
 1244968  1244972  1244976
1244980  1244984  1244988

l[0] = 1244968
l[1] = 1244980

l = 1244968
Press any key to continue
===================================
*/
