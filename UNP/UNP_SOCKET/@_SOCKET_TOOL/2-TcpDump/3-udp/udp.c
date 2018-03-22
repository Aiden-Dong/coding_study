#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>
#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>

pcap_t 				*pcapfd;
char          pcap_buf[64];				      // receive the message for error
char          *dev_name = "enp0s25";		// Network device name

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
	char                 *cmd	= "";
	const uint8_t	       *ptr, *data;
	struct in_addr		   inter_addr, mask_addr;
	char		 	           src_addr[INET_ADDRSTRLEN], dst_addr[INET_ADDRSTRLEN];
	char				         inter_addr_name[INET_ADDRSTRLEN];
	char				         mask_addr_name[INET_ADDRSTRLEN];
  char                 ipsrc[INET_ADDRSTRLEN];  // 数据包源ip地址
  char                 ipdst[INET_ADDRSTRLEN];  // 数据包目的ip地址
	struct bpf_program	 fcode;
	struct pcap_pkthdr	 hdr;
	uint16_t		         mac_type ;
	uint16_t 		         mac_op;
  uint8_t              ip_type;
  uint8_t              iplen;
  uint8_t              *udpdata;
  uint16_t             *sport, *dport;
  uint16_t             *udplen;

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

			mac_type = ntohs(*(uint16_t *)(ptr+12));       // 从数据链路层获取数据包类型

			if(mac_type != 0x0800)                         // ip 数据包
				continue;

      data = ptr+ 14;                                // ip数据包开始位置
      ip_type = *(ptr+23);                           // 数据包类型
      iplen = (*data & 0x0f) * 4;                    // 地址长度
      udpdata = data + iplen;                        // 获取udp首部

      if(ip_type != 17)
        continue;

      sport = (uint16_t *)udpdata;                    // 源端口
      dport = (uint16_t *)(udpdata + 2);              // 目的端口
      udplen= (uint16_t *)(udpdata + 4);              // udp 长度

			if(argc == 2)
			{
				if(strncmp(src_addr, argv[1], INET_ADDRSTRLEN))
					continue;
			}
			
      if(argc == 3)
      {
        if(atoi(argv[2]) != 0)
        {
          if(atoi(argv[2]) != ntohs(*dport))
            continue;
        }
      }

      if(inet_ntop(AF_INET, data+12, src_addr, INET_ADDRSTRLEN) == NULL)
        err_sys("inet_ntop error");


			puts("=========================================================================");
			printf("Package size : %d\n", hdr.caplen);
			printf("Head Data:\n");

			puts("----------------------------------------------");
      // 链路层首部
      printf("%02x:%02x:%02x:%02x:%02x:%02x||%02x:%02x:%02x:%02x:%02x:%02x||%04x\n",
									ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5],
									ptr[6], ptr[7], ptr[8], ptr[9], ptr[10], ptr[11], mac_type);
      //ip首部

		  printf("ip-type: %d\n", ip_type);
			printf("ip-len : %d\n", iplen);
      printf("src : %s\n", inet_ntop(AF_INET, data+12, src_addr, INET_ADDRSTRLEN));
      printf("dst : %s\n", inet_ntop(AF_INET, data+16, dst_addr, INET_ADDRSTRLEN));

      // UDP 首部

      printf("sport : %d\n", ntohs(*sport));
      printf("dport : %d\n", ntohs(*dport));
      printf("udplen: %d\n", ntohs(*udplen)-8);
      write(STDOUT_FILENO, udpdata+8, ntohs(*udplen)-8);
      printf("\n");

			puts("========================================================================\n\n");
		}
	}
	return 0;
}
