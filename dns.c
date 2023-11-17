#include<stdio.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<errno.h>
void main(){
    struct hostent *hen;
    char hostname[100];
    printf("enter hostname: ");
    scanf("%s",hostname);
    hen = gethostbyname(hostname);

    printf("Hostname: %s\n",hen->h_name);
    printf("IP address: %s",inet_ntoa(*((struct in_addr *)hen->h_addr_list[0])));
}