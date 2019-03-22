#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<errno.h>


int main()
{

    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    assert(sockfd!=-1);
    if(sockfd == -1)
    {
        perror("socket error");
        return -1;
    }

    struct sockaddr_in saddr;
    struct sockaddr_in raddr;

    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(6000);
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);


    int ret=bind(sockfd,(struct sockaddr*)&saddr,sizeof(struct sockaddr));
    assert(ret!=-1);
    if(ret == -1)
    {
        perror("ret error");
        return -1;
    }

    int val=sizeof(struct sockaddr);

    while(1)
    {
        char buff[128]={0};
        
        recvfrom(sockfd,buff,127,0,(struct sockaddr*)&raddr,&val);

        printf("ip=%s,port=%d,buff=%s\n",inet_ntoa(raddr.sin_addr),ntohs(raddr.sin_port),buff);

        sendto(sockfd,"ok",2,0,(struct sockaddr*)&raddr,sizeof(raddr));

    }

    close(sockfd);
    return 0;
}




