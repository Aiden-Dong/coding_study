#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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

// 获取主机信息
void show_hostmsg(const struct hostent *host_msg);
// 获取网络名和网络编号
void show_netmsg(const struct netent *net_msg);
// 获取协议信息
void show_protomsg(const struct protoent *proto_msg);
// 获取服务数据库信息
void show_servmsg(const struct servent *serv_msg);

int main()
{
	// 数据被保存到静态区
	struct hostent 	*host_msg;	// 主机信息
	struct netent 	*net_msg;	// 网络信息
	struct protoent *proto_msg;	// 协议信息
	struct servent 	*serv_msg;	// 网络协议数据库

	/*
  	 ******************************************************
 	 *  获取主机信息
 	 *******************************************************
 	 */
	
	printf("获取主机信息\n");
	sethostent(1);			// 打开主机数据库文件并进行回绕

	while(host_msg = gethostent())
	{
		puts("=========================================");
		show_hostmsg(host_msg);
	}
	endhostent();

	/*
 	******************************************************** 
	* 获取网络名字和网络编号
	********************************************************	
 	*/
	puts("获取网络名字和网络编号");
	setnetent(1);    	
	while(net_msg = getnetent())
	{
		puts("=========================================");
		show_netmsg(net_msg);
	}
	endnetent();
	
	/*
 	* ******************************************************
 	* 协议名和协议编号之间的映射
 	* ******************************************************
 	*/

	puts("获取协议信息 :");
	setprotoent(1);
	while(proto_msg = getprotoent())
	{
		puts("=======================================");
		show_protomsg(proto_msg);
	}
	endprotoent();

	/*
 	*******************************************************
	* 获取服务数据库
 	*******************************************************
 	*/	 	
/*
	puts("获取服务数据库:");
	setservent(1);
	while(serv_msg = getservent())
	{
		puts("=====================================");
		show_servmsg(serv_msg);
	}
	endservent();*/
	return 0;
}

void show_servmsg(const struct servent *serv_msg)
{
	int i;
	static int num;

	printf("serv_msg name : %s\n",serv_msg->s_name);
	for(i = 0; serv_msg->s_aliases[i] != NULL; i++)
		printf("serv_msg aliases : %s\n", serv_msg->s_aliases[i]);
	printf("serv_msg port  : %d\n", serv_msg->s_port);
	printf("serv_msg proto : %s\n", serv_msg->s_proto);
	if(++num == 10)
	{
		getchar();
		num = 0;
	}
}
void show_protomsg(const struct protoent *proto_msg)
{
	int i; 
	printf("proto_msg name : %s\n", proto_msg->p_name);
	for(i = 0; proto_msg->p_aliases[i] != NULL; i++)
		printf("proto_msg aliases : %s\n", proto_msg->p_aliases[i]);
	printf("proto_msg protocol : %d\n", proto_msg->p_proto);
}

void show_netmsg(const struct netent *net_msg)
{
	int i;
	char net_addr[INET_ADDRSTRLEN];

	printf("net_msg : %s\n", net_msg->n_name);
	
	for(i = 0; net_msg->n_aliases[i] != NULL; i++)
		printf("net_msg aliases : %s\n", net_msg->n_aliases[i]);
	
	switch(net_msg->n_addrtype)
	{
        case AF_INET:
                puts("host_msg : AF_INET");
                break;
        case AF_INET6:
                puts("host_msg : AF_INET6");
                break;
        case AF_UNIX:
                puts("host_msg : AF_UNIX");
                break;
        default:
                puts("host_msg : sorry");
                break;
        }
	
	printf("net_msg net: %s\n", 
		inet_ntop(AF_INET, (void *)&net_msg->n_net, net_addr,INET_ADDRSTRLEN));

}
void show_hostmsg(const struct hostent *host_msg)
{
	int i = 0;
	char host_addr[INET_ADDRSTRLEN];

	printf("host_msg name : %s\n", host_msg->h_name);
	
	while(host_msg->h_aliases[i] != NULL)
		printf("host_msg aliases : %s\n", host_msg->h_aliases[i++]);

	switch(host_msg->h_addrtype)
	{
	case AF_INET:
		puts("host_msg : AF_INET");
		break;
	case AF_INET6:
		puts("host_msg : AF_INET6");
		break;
	case AF_UNIX:
		puts("host_msg : AF_UNIX");
		break;
	default:
		puts("host_msg : sorry");
		break;
	}

	i = 0;

	while(host_msg->h_addr_list[i] != NULL)
		printf("host_msg addr : %s\n", inet_ntop(AF_INET, 
		host_msg->h_addr_list[i++], host_addr, INET_ADDRSTRLEN));
}
