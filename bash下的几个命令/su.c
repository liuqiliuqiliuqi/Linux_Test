#define _XOPEN_SOURCE
#include <unistd.h>  
#include <stdio.h>  
#include <string.h>  
#include <pwd.h>  
#include <stdlib.h>  
#include <assert.h>  
#include <shadow.h>  
#include <sys/types.h>  
#include <termios.h>  
int main(int argc, char *argv[])  
{  
    char *s = "root";  
    if (argc == 2)  
    {  
        s = argv[1];  
    }
      
    struct passwd *p = getpwnam(s);
    if (p == NULL)  
    {  
           perror("username error");  
    }  
      
    struct spwd *sp = getspnam(s);  
    if(sp == NULL)  
    {  
        perror("userpasswd error");  
        exit(0);  
    }  
    printf("input passwd:");  
    fflush(stdout);  
      
    struct termios saveold, newreset;  
    tcgetattr(fileno(stdin), &saveold);  
    newreset = saveold; 
    newreset.c_lflag &= ~ECHO;  
    char buff[128] = {0}; 
    if (tcsetattr(fileno(stdin), TCSAFLUSH, &newreset) != 0)  
    {  
       
       perror("wrong happened\n");  
    }  
    else  
    {  
            fgets(buff,128,stdin);  
            buff[strlen(buff)-1] = 0;  
            tcsetattr(fileno(stdin), TCSANOW, &saveold); 
    }  
    char lt[128] = {0};  
    int i = 0;  
    int num = 0;  
    for(;i<strlen(sp->sp_pwdp);i++)
    {  
        if(sp->sp_pwdp[i] == '$')  
        {  
            num += 1;  
            if(num == 3)  
            {  
                break;  
            }  
        }     
        lt[i] = sp->sp_pwdp[i];  
    }  
  
    char *pw = crypt(buff,lt);  
    if(strcmp(pw,sp->sp_pwdp) != 0)
    {  
        printf("failed\n");  
        exit(0);  
    }  
    printf("success\n");  
         
    pid_t pid = fork();
    assert(pid != -1);  
       
    if (pid == 0)  
    {  
        setuid(p->pw_uid); 
        setenv("HOME",p->pw_dir,1); 
        execl(p->pw_shell,p->pw_shell,(char *)0); 
        ("exec error");
        exit(0);  
    }  
    wait(NULL); 
}
