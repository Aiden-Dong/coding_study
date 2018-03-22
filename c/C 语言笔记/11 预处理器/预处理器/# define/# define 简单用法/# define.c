/* preproc.c - 简单的预处理器的例子 */
#include <stdio.h>

#define TWO 2
#define OW "Consistency is the last refuge of the unimagia\
tive. - Oscar Wilde" /* 反斜线把这个定义延续到下一行 */
#define FOUR TWO*TWO
#define PX printf("X is %d.\n", x)
#define FMT "X is %d.\n"

const int IN = 30 ;

//static int a = IN ;  // error 
static int a = TWO ;
 int main (void)
{
	int s = IN;
    int x = TWO;
 
    PX;
    x = FOUR;
    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");
 
    return 0;
}
/* 
在 VC++6.0 的运行环境中:
=============================
X is 2.
X is 4.
Consistency is the last refuge of the unimagiative. - Oscar Wilde
TWO: OW
Press any key to continue
==========================
*/