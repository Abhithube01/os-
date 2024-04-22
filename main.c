#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid_t p;
    int w;

    p = fork();

    if(p==0)
    {
        printf("my child is having id %d\n",getpid());
        printf("my parent is having id %d\n",getppid());
        execl("./mycp","mycp",NULL);
    }
    else
    {
        printf("i am child  having id %d\n",p);
        printf("my parent is having id %d\n",getpid());
        wait(&w);
        execl("./mycp","mycp",NULL);
    }
    return 0;
}