#include <stdio.h>

int main ()
{
	FILE *fp1 , *fp2 ;
	int nline ;
	char lpBuf[100];

	fp1 = fopen("one.txt", "r");
	fp2 = fopen("two.txt", "w");

	memset(lpBuf, 0, sizeof(lpBuf));

	while(nline = fread(lpBuf, sizeof(lpBuf), 1, fp1))
	{
		printf ("nline = %d\n",nline);
		fwrite(lpBuf, nline, 1, fp2);
		memset (lpBuf, 0, sizeof(lpBuf));
	}
	fwrite(lpBuf, sizeof(lpBuf), 1, fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}