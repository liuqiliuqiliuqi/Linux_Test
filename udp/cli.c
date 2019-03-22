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

    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(6000);
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    int  on=1;
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

    while(1)
    {
        char buff[128]={0};
        printf("input:\n");
        fgets(buff,128,stdin);
        if(strncmp(buff,"end",3)==0)
            {
                break;
            }

       int  ret=sendto(sockfd,buff,127,0,(struct sockaddr*)&saddr,sizeof(struct sockaddr));
        if(ret<0)
        {
            perror("sendto error");
        }

    }

    close(sockfd);
    return 0;
}




