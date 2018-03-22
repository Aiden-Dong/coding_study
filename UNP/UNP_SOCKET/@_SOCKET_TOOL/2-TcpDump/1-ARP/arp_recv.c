#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>
#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

pcap_t 				*pcapfd;
char pcap_buf[64];				// receive the message for error
char *dev_name = "enp0s25";		// Network device name

void err_que(const char*msg)
{
	puts(msg);
	exit(0);
}
void err_sys(const char *msg){
	printf("%s : %s\n", msg, pcap_geterr(pcapfd));
	exit(0);
}

void err_pcap(const char *msg)
{
	printf("%s : %s\n", msg, pcap_buf);
	exit(0);
}

int main(int argc, char *argv[])
{
	char *cmd	= "";
	const unsigned char	*ptr, *data;
	struct in_addr		inter_addr, mask_addr;
	char		 	     src_addr[INET_ADDRSTRLEN], dst_addr[INET_ADDRSTRLEN];
	char				inter_addr_name[INET_ADDRSTRLEN];
	char				mask_addr_name[INET_ADDRSTRLEN];
	struct bpf_program	fcode;
	struct pcap_pkthdr	hdr;
	unsigned short 		mac_type ;
	unsigned short 		mac_op;

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

	// Get ARP Package
	while(1)
	{
		if((ptr = (unsigned char *)pcap_next(pcapfd, &hdr))!= NULL)
		{

			
			mac_type = ntohs(*(unsigned short *)(ptr+12));
			if(mac_type != 0x0806)
				continue;
			data = ptr+ 14;
			mac_op = ntohs(*(unsigned short *)(data+6));

			puts("=========================================================================");
			printf("Package size : %d\n", hdr.caplen);
			printf("Head Data:\n");
			printf("Package Data: ---- %s\n", 
				(mac_op == 1) ? "ARP 璇锋眰" : ((mac_op == 2) ? "ARP 搴旂瓟" : "OTHER"));
			puts("----------------------------------------------");
			printf("%02x:%02x:%02x:%02x:%02x:%02x||%02x:%02x:%02x:%02x:%02x:%02x||%04x\n", 
									ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], 
									ptr[6], ptr[7], ptr[8], ptr[9], ptr[10], ptr[11], mac_type);
			printf("%04x||%04x||%02x||%02x||%04x || ", ntohs(*(unsigned short*)(data)), 
												    ntohs(*(unsigned short*)(data+2)),
												    *(data+4), *(data+5), mac_op);
			printf("%02x:%02x:%02x:%02x:%02x:%02x||%s||%02x:%02x:%02x:%02x:%02x:%02x||%s\n",
				data[8],data[9],data[10],data[11],data[12],data[13],
				inet_ntop(AF_INET, (data+14), src_addr, INET_ADDRSTRLEN),
				data[18],data[19],data[20],data[21],data[22],data[23],
				inet_ntop(AF_INET, (data+24), dst_addr, INET_ADDRSTRLEN)
				);
			puts("----------------------------------------------");
			if(hdr.caplen > 28)
			printf("%02x:%02x:%02x:%02x:%02x:%02x\n", data[28], data[29], data[30], data[31], data[32], data[33]);
			puts("========================================================================\n\n");
		}
	}
	return 0;
}
