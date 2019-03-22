#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("mkdir error");
    }

    if((mkdir(argv[1],0770))!=0)
    {
        perror("mkdir error");
        exit(-1);
    }

    exit(0);


}


