#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_arp.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <complex.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <stdlib.h>
int main(int argc ,char* argv[])
{
    struct arpreq myarp;
    int sd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in sin;
    char *ptr;
    sin.sin_family = AF_INET;
    inet_aton(argv[1],&sin.sin_addr);
    memcpy(&myarp.arp_pa,&sin,sizeof(myarp.arp_pa));
    if(ioctl(sd,SIOCGARP,&myarp)==1){
        printf("no arp cache found\n");
        exit(1);
    }
    ptr= &myarp.arp_pa.sa_data[0];
    printf("the mac address is: %x:%x:%x:%x:%x:%x\n",ptr[0],ptr[1],ptr[2],ptr[3],ptr[4],ptr[5]);
    return 0;
}
