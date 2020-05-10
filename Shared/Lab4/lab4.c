#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid;
    printf ("Main start here my pid is %d\n", getpid());
    pid = fork();
    if(pid == 0){
    printf("This is a child process. My pid is %d, my child pid is %d\n", getpid(), getppid());
    printf("My status is %d\n\n", pid);
      if(execv("./helloWorld", NULL)<0){
        perror("execv");
      }
    }else{
      wait(0);//The wait() system call suspends execution of the calling thread until one of its children terminates. 
      printf("Main existing, my pid is %d\n", getpid() );
    }
    return 0;
}
