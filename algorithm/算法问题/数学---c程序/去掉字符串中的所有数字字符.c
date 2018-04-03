/*去掉字符串中的所有数字字符*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
char s[41];
int i=0,n=0;
printf("请输入字符串");
gets(s);
while(s[i])
{
if(s[i]>='0'&&s[i]<='9')//舍弃数字字符
{
i++;
continue;
}
s[n]=s[i];//存储非数字字符
n++;
i++;
}
s[n]='\0';
printf("%s",s);//输出整个字符串，而不是某个字符
return 0;
}