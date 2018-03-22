#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main()
{
	char *ptr;
	int i = 0;
	char addr_buf[INET_ADDRSTRLEN]; 		// 获取点分十进制的ip
	unsigned int addr_val = 0xffffffff;		// ip 的内部表示		
	unsigned int val = 0x1a2b3c4d;
	char buf[10] = "hello one";

	ptr =(char *)&val;
	printf("字节序问题 :\n");
	printf("=====================================\n");
	printf("%0x\n", val);
	for(i = 0; i < 4; i++)
		printf("%0x --- %0x\n", ptr[i], &ptr[i]);
	printf("====================================\n");
	for(i = 0 ; i < 10; i++)
		printf("%c --- %0x\n", buf[i], &buf[i]);

	printf("====================================\n");

	puts("ip 转换成点分十进制表示 :");
	if(inet_ntop(AF_INET, (void*)&addr_val, addr_buf, INET_ADDRSTRLEN) == NULL)
		err_sys("inet_ntop error");  // 将 ip 从二进制转换成点分十进制的字符串表示
	printf("二进制的点分十进制表示 : %s\n", addr_buf);

	if(inet_pton(AF_INET, "192.168.1.1",(void *)&addr_val) == -1)
		err_sys("inet_pton error");
	printf("ip 的二进制表示（网络） : %0x\n", addr_val);   // 网络的数据用的是大端表示法
	printf("ip 的二进制表示（本地） : %0x\n", ntohl(addr_val));

	return 0;
}
