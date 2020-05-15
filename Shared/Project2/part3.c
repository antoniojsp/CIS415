#include <stdio.h>//base
#include <string.h>// for strcpy and demas
#include <stdlib.h>
#include <unistd.h>//exec and so
#include <sys/types.h>
#include <sys/wait.h>//waitpid
#include <signal.h>
#include "utilities.h"
#include <wait.h>

#define PROCESS_RUNNING_TIME 3//time in seconds to send alert
#define NUMBER_LINES 50
#define BUFFER_LENGTH 50//number of char per line in input
#define TOKENS_NUMBER 10//number of parameters per line
#define PARAMETER_LENGTH 40//number of character per paramaenter


//https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define ANSI_COLOR_CYAN    "\x1b[36m"// colors!
#define ANSI_COLOR_RESET   "\x1b[0m"

int indicator = 1;//if 1, true and while loop continue
void continue_loop(int signo){// gets signals and change indicator to be able to continue with the loop.
    indicator = 0;
}

int tiempo = 1;//if 1, true and while loop continue
void relog(int signo){
    tiempo = 0;
}


int main(int argc, char** argv){
  char bucle[30] ="##############################";
  printf("%s %s %s\n", bucle,"Part 3",bucle);

  char** lista = char_two(NUMBER_LINES, BUFFER_LENGTH);// linea de comandos
  int number_lines = read_file(argv, lista);// lineas enteras
  char **tokens= char_two(TOKENS_NUMBER, PARAMETER_LENGTH);//where we storage the tokens
  char* linea = char_one(BUFFER_LENGTH);//save a line at the time

  pid_t child[number_lines];//save the porcesses running

  if (signal(SIGUSR1, continue_loop) == SIG_ERR || signal(SIGALRM, relog) == SIG_ERR) {// to get the signals
      return -1;
  }
  printf("The number of programs to schedule is %d.\n", number_lines);
  for (int i = 0; i < number_lines; i++) {

      int numero = get_tokens(lista[i],tokens);// gets tokens with the arguments and numero with the number of tokens
      pid_t pid = fork();//fork process
      if(pid < 0){// if fails, exit and return 1.
        exit(1);
      }
      if(pid == 0) { //pid 0 indicates child
        tokens[numero] = NULL;//add NULL at the end to indicate the end of the array. requires for execvp

        printf(" * Program %d fork and waiting.\n",i);

        indicator = 1;// set to 1 to keep the loop rolling till the signal is sent and the value is changed to 1.
        while(indicator){// trap the execution of exec till the sigusr1 signal is sent by kill()
            sleep(1);
        }
        execvp(tokens[0],tokens);
        printf(" ---> Command line number %d is invalid!. <----\n ", i);
        number_lines--;//in case of invalid commands
        exit(1);//case it fails
      }
      else{
        child[i] =  pid;//save the children in an array to start and stop later.
      }
  }
  sleep(1);
  printf("%s\n"," * Sending signal to add exec() to all the children. " );
  for (int i = 0; i < number_lines; i++) {//launching exec for all the fork children and stopping to wait for the schedule
    kill(child[i],SIGUSR1);
    kill(child[i],SIGSTOP);
  }

  int status;// to save the status
  int i = 0;
  int suma = 0;
  int *done = (int*)calloc(number_lines,sizeof(int));//array to calculate when it ends.
  char *temp = char_one(BUFFER_LENGTH);


  while(1) {
    int finish = waitpid(child[i], &status, WNOHANG);
    if (finish == 0)//if it is not finish, it gives 0
    {
      strcpy(temp,lista[i]);
      temp[strlen(temp)-1] = 0;//temporal to get the command line that is being processing.
      // printf("\033[0;32m");
      printf(ANSI_COLOR_CYAN"\n ------- Starting process number %d (%s). -------"ANSI_COLOR_RESET"\n", i, temp);
      // printf("\033[0m");
      kill(child[i], SIGCONT);//stop child
      tiempo = 1;//set up infinite loop till alarm is send
      alarm(PROCESS_RUNNING_TIME);
      while(tiempo){}//loop waiting for the alarm to send back signal.
      kill(child[i], SIGSTOP);
      if (!waitpid(child[i], &status, WNOHANG)) {
          printf(ANSI_COLOR_CYAN" ------- Stoping process number %d and restarting the next process in line. -------"ANSI_COLOR_RESET"\n", i );
      }else{
          printf(ANSI_COLOR_CYAN" ------- Done with process number %d. Now next process in line -------"ANSI_COLOR_RESET"\n", i );
      }
    }

    int finish1 = waitpid(child[i], &status, WNOHANG);

    if(finish1!=0){// add 1 to the array index i that tells if all the process number i is done
      done[i] = 1;
    }

    int sumatoria = 0;
    for (int i = 0; i < number_lines; i++) {// checks if all the child have exits.
      sumatoria = sumatoria + done[i];// it will sum the number of programs and will indicate it is done.
    }
    if(sumatoria >= number_lines){//if sumatoria is equal to the number of children, then it exits.
      break;
    }
    i++;
    if(i>number_lines-1){//it returns to the beginning of the array.
      i = 0;
    }
  }


  printf("%s\n", "* Continue with all process and waiting for all the process to be done and then kill the parent.");
  for(int j = 0; j < number_lines; j++){
       wait(0);
  }

  printf("%s\n","* Finishing parent." );
  free(linea);
  free2d(tokens, TOKENS_NUMBER);
  free2d(lista, NUMBER_LINES);
  free(done);
  free(temp);
  return 0;
}
