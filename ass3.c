#include <stdio.h>
#include<unistd.h>
#include<assert.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
   int fd[2],pid;
   int rfiledes = open("input.txt",O_RDONLY);
   int wfiledes = open("output.txt",O_WRONLY);

   dup2(rfiledes,fileno(stdin));
   dup2(wfiledes,fileno(stdout));

   close(rfiledes);
   close(wfiledes);

   if(pipe(fd) == 0)
   {
    pid = fork();
    if(pid == 0)
    {
        dup2(fd[1],fileno(stdout));
        close(fd[0]);
        close(fd[1]);
        execl("/bin/sort","sort",NULL);
    }
    else if(pid > 0)
    {
        dup2(fd[0],fileno(stdin));
        close(fd[0]);
        close(fd[1]);
        execl("/bin/uniq","uniq",NULL);
    }
    else{
        perror("fork");
        exit(1);
    }
   }
   else{
    printf("pipe is not created");
   }
}