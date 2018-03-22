# include < stdio.h >

int main (void)
{
	char str1[] = {'H','e','l','l','o','w'};
	char str2[]="hellow";

	puts (str1);
	puts (str2);

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
Hellow烫?.
hellow
Press any key to continue
==============================
*/