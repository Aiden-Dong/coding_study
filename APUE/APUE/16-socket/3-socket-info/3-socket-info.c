#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void show_addrinfo(const struct addrinfo *addr_msg);
void exit_fun();

int main()
{
	int i = 0, j;

	char hostname[30];
	char servname[30];
	struct hostent 	*host_msg;
	struct servent 	*serv_msg;
	struct addrinfo *addr_msg, *addr_nextmsg, addr_ini;
	
	atexit(exit_fun);
	
	memset(&addr_ini, 0, sizeof(addr_ini));
	memset(hostname, 0, 30);
	memset(servname, 0, 30);

	// 过滤器
	addr_ini.ai_flags = AI_PASSIVE;
	addr_ini.ai_family = AF_INET;
	
	sethostent(1);
	host_msg = gethostent();

	
	setservent(1);

	while(getchar() == '\n' && ++i)
	{
		printf("========================================\n");

		for(j = 0; j < i; j++)
			serv_msg = getservent();

		strcpy(hostname, host_msg->h_name);
		strcpy(servname, serv_msg->s_name);

		printf("host_msg -- name : %s\n", hostname);
		printf("serv_msg -- name : %s\n", servname);

		getaddrinfo(hostname, servname, &addr_ini, &addr_msg);

		addr_nextmsg = addr_msg;

		while(addr_nextmsg)
		{
			show_addrinfo(addr_nextmsg);

			if (addr_nextmsg->ai_next != NULL)
			 	addr_nextmsg = addr_nextmsg->ai_next;
			else
				break;
		}

		freeaddrinfo(addr_nextmsg);

	}

	return 0;
}

void exit_fun()
{
	puts("清理函数");
	endservent();
}
void show_addrinfo(const struct addrinfo *addr_msg)
{
	char ip_addr[INET_ADDRSTRLEN];
	struct sockaddr_in *addr_sock;

	addr_sock = (struct sockaddr_in *)addr_msg->ai_addr;

	switch(addr_msg->ai_family)
	{
	case AF_INET:
		puts("domain : AF_INET");
		break;
	case AF_INET6:
		puts("domain : AF_INET6");
		break;
	case AF_UNIX:
		puts("domain : AF_UNIX");
		break;
	default:
		puts("domain : sorray");
		break;
	}

	switch(addr_msg->ai_socktype)
	{
	case SOCK_DGRAM:
		puts("socktype : SOCK_DGRAM");
		break;
	case SOCK_STREAM:
		puts("socktype : SOCK_STREAM");
		break;
	case SOCK_RAW:
		puts("socktype : SOCK_RAW");
		break;
	case SOCK_SEQPACKET:
		puts("socktype : SEQPACKET");
		break;
	default:
		puts("socktype : sorray");
		break;
	}
	switch(addr_msg ->ai_protocol)
	{
	case IPPROTO_IP:
		puts("protocol : IPPROTO_IP");
		break;
	case IPPROTO_ICMP:
		puts("protocol : IPPROTO_ICMP");
		break;
	case IPPROTO_RAW:
		puts("protocol : IPPROTO_RAW");
		break;
	case IPPROTO_TCP:
		puts("protocol : IPPROTO_TCP");
		break;
	case IPPROTO_UDP:
		puts("protocol : IPPROTO_UDP");
		break;
	default:
		puts("protocol : sorroy");
	}

	printf("ip: %s\n", 
		inet_ntop(addr_msg->ai_family,(void *)&addr_sock->sin_addr.s_addr,
		      	  ip_addr, INET_ADDRSTRLEN));
}
