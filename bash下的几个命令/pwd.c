#include<stdio.h>
#include<stdlib.h>

int main()
{
    char buff[128]={0};
    getcwd(buff,128);

    printf("%s\n",buff);
    return 0;
}
