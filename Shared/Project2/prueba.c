// #include <stdio.h>
// #include <stdlib.h> //for exit() function
// #include <unistd.h>
// #include <signal.h>
// #include <wait.h>
// #include <sys/types.h>
//
// static void catchAlarm(int signo);
//
// int main(void){
//
//     int status;
//     pid_t pid;
//
//     signal(SIGALRM, catchAlarm);
//     pid = fork();
//
//     if(pid < 0){
//         printf("Problem forking process.\n");
//         printf("Exiting now...\n");
//         exit(EXIT_FAILURE);
//     }
//
//     if(pid==0){
//         alarm(1);
//         for(int i = 0; i < 7; i++){
//             printf("In child process... %d\n", i);
//             sleep(1);
//         }
//     } else     {
//         wait(&status);
//         alarm(3);
//         for(int i = 0; i < 15; i++){
//             printf("In parent process... %d\n", i);
//             sleep(1);
//         }
//     }
//
// }
// static void catchAlarm(int signo){
//     printf("Caught an SIGALRM signal.\n");
//     printf("Signal value = %d\n", signo);
//
//     printf("Exiting from process...\n");
//
//     //in stdlib.h header file
//     exit(EXIT_SUCCESS);
//
// }




// C code to find the exit status of child process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <wait.h>

int indicator = 1;//if 1, true and while loop continue
void continue_loop(int signo){
    indicator = 0;
}

int tiempo = 1;//if 1, true and while loop continue
void relog(int signo){
    tiempo = 0;
}

// Driver code
int main(void)
{

  int status;
  int status1;

  if (signal(SIGUSR1, continue_loop) == SIG_ERR || signal(SIGALRM, relog) == SIG_ERR) {// to get the signals
      return -1;
  }


    pid_t pid;
    pid = fork();
    if ( pid == 0 )
    {
          char *args[]={"./hola","100",NULL};
          while(indicator){
            sleep(1);
          }
          execvp(args[0],args);
          exit(1);
    }

    pid_t pid1 = fork();
    if ( pid1 == 0 )
    {
          char *args[]={"./hello",NULL};
          while(indicator){
            sleep(1);
          }
          execvp(args[0],args);
          
          exit(1);
    }
    kill(pid,SIGUSR1);
    kill(pid, SIGSTOP);
    kill(pid1,SIGUSR1);
    kill(pid1, SIGSTOP);

    int i = 0;
    while(waitpid(pid, &status, WNOHANG) == 0 || waitpid(pid1, &status1, WNOHANG) == 0) {
      // printf("%d\n",i++ );
      int dar = waitpid(pid, &status, WNOHANG);
      if (!dar)
      {
        // printf("%s\n","hola 1" );
        kill(pid, SIGCONT);
        tiempo = 1;
        alarm(3);
        while(tiempo){}
        kill(pid, SIGSTOP);
      }

      int rec = waitpid(pid1, &status1, WNOHANG);
      if (!rec)
      {
        // printf("%s\n","hola 2" );
        kill(pid1, SIGCONT);
        tiempo = 1;
        alarm(3);
        while(tiempo){}
        kill(pid1, SIGSTOP);
      }
    }

    waitpid(pid, &status, 0);
    if ( WIFEXITED(status) )
    {
        int exit_status = WEXITSTATUS(status);
        printf("Termination: %d\n",WTERMSIG(status));

        printf("Exit status of the child HOLA was %d\n",
                                     exit_status);
    }else{
      printf("%s\n","NO" );
    }

    waitpid(pid1, &status1, 0);
    if ( WIFEXITED(status) )
    {
        int exit_status = WEXITSTATUS(status);
        printf("Exit status of the child HELLO was %d\n",
                                     exit_status);
    }else{
      printf("%s\n","NO" );
    }

    return 0;
}

/* number of times the handle will run: */
// volatile int breakflag = 10;
//
// void handle(int sig) {
//     printf("Hello\n");
//     --breakflag;
//     alarm(1);
// }

// int main() {
//     // signal(SIGALRM, handle);
//     pid_t pid = fork();
//     if (pid < 0){
//         printf("%s\n", "Error");
//         exit(1);
//     }
//     if (pid == 0){
//         char *args[]={"./hola","10",NULL};
//         execvp(args[0],args);
//         exit(1);
//     }
//     printf("%s\n","Espera 2." );
//     sleep(2);
//
//
//     kill(getpid(), SIGSTOP);
//     sleep(4);
//     kill(getpid(), SIGCONT);
//     // alarm(10);
//     // while(breakflag) { sleep(1); }
//     // printf("done\n");
//     wait(0);
//     return 0;
// }

// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <sys/wait.h>
//
// int main (){
//     int pid;
//     int status;
//
//
//     pid = fork();
//
//     if (pid == 0){
//
//         printf("Child %d\n", getpid());
//         sleep(2);
//         exit(EXIT_SUCCESS);
//     }
//
//     //Comment from here to...
//     //Parent waits process pid (child)
//
//     waitpid(pid, &status, 0);
//     //Option is 0 since I check it later
//
//     if (WIFSIGNALED(status)){
//         printf("Error\n");
//     }
//     else if (WEXITSTATUS(status)){
//         printf("Exited Normally\n");
//     }
// //To Here and see the difference
//     printf("Parent: %d\n", getpid());
//
//     return 0;
// }
