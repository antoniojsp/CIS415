#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

  pid_t children[5];
  // printf("Dad: %d\n",getpid() );
  for(int i = 0; i < 5; i++) {
    pid_t pid = fork();
    if(pid<0){
      // printf("%s\n","Algo salio mal" );
      break;
    }
    if(pid == 0) { //this is the child (don't forget to check for errors and what-not)
      char *args[]={"ls","-a","-r","-s", NULL};
      // printf("children %d\n", getpid());
      execvp(args[0],args);
      exit(1);
    }
    else{
      children[i] =  pid;
    }
  }

  for(int j = 0; j < 5; j++){
      waitpid(children[j], NULL, 0);
  }
  // printf("Dad: %d\n",getpid() );

  return 0;
}
