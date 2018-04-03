/*回文串*/
#include<stdio.h>
#include<string.h>
int main()
{
int i,j,length;
char s[41];
gets(s);
length=strlen(s);
for(i=0,j=length-1;i<j;i++,j--)//s[6]实际上是s[0],s[1],s[2],s[3],s[4],s[5]
{
if(s[i]!=s[j])
break;
}
if(i>j)
printf("%s是回文串",s);
else
printf("%s不是回文串",s);
return 0;
}