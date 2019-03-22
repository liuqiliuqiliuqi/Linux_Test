#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("rm error");
    }

    if(unlink(argv[1])!=0)
    {
        perror("unlink error");
        exit(-1);
    }

    exit(0);


}


