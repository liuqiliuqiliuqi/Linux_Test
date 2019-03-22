#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc,char *argv[],char*envp[])
{
    while(1)
    {
        printf("stu@localhost~]$");
        fflush(stdout);

        char buff[128]={0};   
        fgets(buff,128,stdin);

        int k=0;
        for(k=0;buff[k]!='\0';k++)
        {
            if(buff[k]=='\n')
            {
                buff[k]=0;
                break;
            }

        }


        char *my_argv[128];
        char *p=buff;
        my_argv[0]=p;
        int i=0;int j=1;
        while(buff[i]!='\0')
        {
            if(*p==' ')
            {
                *p='\0';
                p++;
                my_argv[j]=p;
                j++;

            }
            else
            {
                p++;

            }
            i++;
        }
        my_argv[j]=0;

        if(strncmp(buff,"exit",4)==0)
        {
            break;
        }

        pid_t pid=fork();
        assert(pid!=-1);

        if(pid==0)
        {
            execvp(my_argv[0],my_argv);
            perror("execvp error");
            exit(0);
        }
        wait(NULL);

    }
    exit(0);
}
