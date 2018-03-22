#include<stdio.h>

int file_copy(char *oldname,char *newname);

int main()
{
char source[80],destination[80];//两个文件名

printf("\n输入文件一名:");
gets(source);
printf("输入文件二名");
gets(destination);

if(file_copy(source,destination)==0)//调用函数
  puts("成功");
 else
   fprintf(stderr,"失败");
   return 0;
}
//将第一个文件内容复制到第二个文件中
int file_copy(char *oldname,char *newname)//复制文件函数
{
 FILE *fold,*fnew;
 int c;
 //以读的方式打开第一个文件
 if((fold=fopen(oldname,"rb"))==NULL)
  return -1;
//以写的形式打开第二个文件
if((fnew=fopen(newname,"wb"))==NULL)
{
  fclose(fold);//关闭第一个文件
  return -1;
  }

//将第一个文件内容读给文件二
  while(1)
  {
  c=fgetc(fold);//读第一个文件的内容
  if(!feof(fold))//检测文件尾
     fputc(c,fnew);//将第一个文件内容读给文件二
  else
	break;
	}
  //关闭文件
	fclose(fnew);
	fclose(fold);
	return 0;
	}