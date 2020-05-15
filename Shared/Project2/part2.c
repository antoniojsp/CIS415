#include <stdio.h>//base
#include <string.h>// for strcpy and demas
#include <stdlib.h>
#include <unistd.h>//exec and so
#include <sys/types.h>
#include <sys/wait.h>//waitpid
#include <signal.h>
#include "utilities.h"
#define NUMBER_LINES 50
#define BUFFER_LENGTH 50//number of char per line in input
#define TOKENS_NUMBER 10//number of parameters per line
#define PARAMETER_LENGTH 40//number of character per paramaenter

int indicator = 1;//if 1, true and while loop continue
void continue_loop(int signo){// gets signals and change indicator to be able to continue with the loop.
    printf("%s\n","* Signal sent to continue with exec." );
    indicator = 0;
}

int main(int argc, char** argv){
  char bucle[30] ="##############################";

  printf("%s %s %s\n", bucle,"Part 2",bucle);

  char** lista = char_two(NUMBER_LINES, BUFFER_LENGTH);// linea de comandos
  int number_lines = read_file(argv, lista);// lineas enteras
  char **tokens= char_two(TOKENS_NUMBER, PARAMETER_LENGTH);//where we storage the tokens
  char* linea = char_one(BUFFER_LENGTH);//save a line at the time

  pid_t children[number_lines];//save the porcesses running

  if (signal(SIGUSR1, continue_loop) == SIG_ERR) {// to get the signals
      return -1;
  }

  for (int i = 0; i < number_lines; i++) {

      int numero = get_tokens(lista[i],tokens);// gets tokens with the arguments and numero with the number of tokens

      pid_t pid = fork();//fork process

      if(pid < 0){// if fails, break.
        break;
      }
      if(pid == 0) { //pid 0 indicates child
        // printf("%s\n", "hola");
        tokens[numero] = NULL;//add NULL at the end to indicate the end of the array. requires for execvp
        printf("* Program %d fork and waiting.\n",i);
        indicator = 1;// set to 1 to keep the loop rolling till the signal is sent and the value is changed to 1.
        while(indicator){// trap the execution of exec till the sigusr1 signal is sent by kill()
            sleep(1);
        }
        execvp(tokens[0],tokens);
        exit(1);//case it fails
      }
      else{
        children[i] =  pid;
      }
  }
  sleep(1);
  printf("%s\n","* Waiting 5 seconds to start with exec.");
  back_timer(5);//timer to see how the exec are started in the fork processess.
  printf("%s\n", "* Continue with exec.");

  for (int i = 0; i < number_lines; i++) {// start the programs
      kill(children[i], SIGUSR1);
  }

  printf("%s\n","* Stop all programs in 5 seconds.");
  sleep(5);
  for (int i = 0; i < number_lines; i++) {//pause the programs
      kill(children[i], SIGSTOP);
  }
  printf("%s\n","* All process stop for 5 seconds. " );

  back_timer(5);//timer to wait till revive the process

  for (int i = 0; i < number_lines; i++) {// restart the programs
      kill(children[i], SIGCONT);
  }

  printf("%s\n", "* Continue with all process and waiting for all the process to be done and then kill the parent.");
  for(int j = 0; j < number_lines; j++){
       wait(0);
  }

  printf("%s\n","* Finishing parent." );
  free(linea);
  free2d(tokens, TOKENS_NUMBER);
  free2d(lista, NUMBER_LINES);
  return 0;
}
