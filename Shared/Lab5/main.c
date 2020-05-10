#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signaler(pid_t a){



}

int main(){

    pid_t pid[5];
    printf("%d\n",getpid() );
    for (int i = 0; i < 5; i++) {
      pid[i] = fork();
      printf("Hola %d\n", pid[i]);
      if(pid[i] == 0)
      {
          printf("%d\n",getpid() );
          execv("hello", NULL);
      }
    }





    return 0;
}
