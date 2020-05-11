#include <stdio.h>//base
#include <string.h>// for strcpy and demas
#include <stdlib.h>
#include <unistd.h>//exec and so
#include <sys/types.h>
#include <sys/wait.h>//waitpid
#include "utilities.h"
#define NUMBER_LINES 50
#define BUFFER_LENGTH 50//number of char per line in input
#define TOKENS_NUMBER 10//number of parameters per line
#define PARAMETER_LENGTH 40//number of character per paramaenter

int main(int argc, char** argv){

  char** lista = char_two(NUMBER_LINES, BUFFER_LENGTH);// linea de comandos
  int number_lines = read_file(argv, lista);// lineas enteras
  char **tokens= char_two(TOKENS_NUMBER, PARAMETER_LENGTH);//where we storage the tokens
  char* linea = char_one(BUFFER_LENGTH);//save a line at the time

  pid_t children[number_lines];
  for (int i = 0; i < number_lines; i++) {

      int numero = get_tokens(lista[i],tokens);
      pid_t pid = fork();//fork process

      if(pid<0){// if fails
        break;
      }
      if(pid == 0) { //this is the child (don't forget to check for errors and what-not)
        tokens[numero] = NULL;//add NULL at the end to indicatethe end.
        // printf("Open: %s %d\n", tokens[0], getpid() );
        execvp(tokens[0],tokens);
        // printf("%s %d\n","Fallo", getpid() );
        exit(1);//case it fails
      }
      else{
        children[i] =  pid;
      }
  }
  for(int j = 0; j < number_lines; j++){
       wait(0);
  }

  free(linea);
  free2d(tokens, TOKENS_NUMBER);
  free2d(lista, NUMBER_LINES);
  return 0;
}
