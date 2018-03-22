//结构变量和结构指针变量作为函数参数传递的问题（正确）
#include<stdio.h>
#include<string.h>
struct Student
{
 int age;
 char name[100];
 char sex;
 };
 void InputStudent(struct Student *);
 void OutputStudent(struct Student *);

 int main()
 {
 struct Student st;

 InputStudent(&st);//对结构体变量的输入  必须发送st地址
 OutputStudent(&st);//对结构体变量的输出  可以发送st的地址也可以发送st的内容，但为了减少内存的耗费，也为了提高运行速率，建议发送地址
 // OutputStudent(st);输出时，发送st的内容也可以
 return 0;
 }
 void InputStudent(struct Student *S1)//对应形参，实参S1=&st
 {

  S1->age=10;//等价于(*st).age
  strcpy(S1->name,"张三");
  S1->sex='F';
  }
   void OutputStudent(struct Student *S2)
   {
   //struct Student *S2 =&st;多余！！！有实参
   printf("%d %s %c\n",S2->age,S2->name,S2->sex);
   }

