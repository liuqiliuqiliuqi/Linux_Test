#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<assert.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
    DIR *dir=opendir(".");
    if(dir==NULL)
    {
        fprintf(stderr,"cannot open directory:%s\n",dir);
        return 0;
    }

    struct stat st;
    struct dirent *rent=NULL;
    while((rent=readdir(dir)))
    {
        if((strncmp(rent->d_name,".",1)==0))
        {
            continue;
        }
        stat(rent->d_name,&st);
        if(S_ISDIR(st.st_mode))
        {
             printf("\e[1;34m %s  \033[0m ",rent->d_name);
        }
        else
        {
            if(st.st_mode&(S_IXUSR|S_IXGRP|S_IXOTH))
            {
                printf("\e[1;32m %s  \033[0m ",rent->d_name);
            }
            else
            {
                printf("%s  ",rent->d_name);
            }
        }

        

    }
    closedir(dir);
    printf("\n");
    exit(0);

}

