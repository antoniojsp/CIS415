#include <stdio.h>
#include <stdlib.h>//standar libr
#include <unistd.h>
#include <fcntl.h>//for open
#include <string.h>//for string
#include <sys/stat.h>//check if file is there
#include "addons.h"
#include <errno.h>
#define MAX_PATH 260

struct stat st = {0};
//NO LEAK!!
int main(){

  char *entrada = char_string(MAX_PATH);
  char *salida = char_string(MAX_PATH);

  strcpy(entrada, "hola11.txt");
  strcpy(salida, "./salida.txt");

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;
  size_t lenght = 3;

  char* answer = char_string(MAX_PATH);
  char* line = char_string(MAX_PATH);
  while(end_loop == 0){//checks if the file exists or no

      if (stat(entrada, &st) == -1){//checking for the file to copy if exists
          printf("File not found.\n");
          break;
      }
      else if(stat(salida, &st) == -1){
          // needs to check that exists.
          int input = open(entrada, O_RDONLY);//source
          if (input < 0){//checker
              printf("Error opening '%s': %s\n",entrada, strerror(errno));//report error
              break;
          }

          int output = open(salida, O_CREAT | O_WRONLY, 0644);//destination
          if (output < 0){//checker
            break;
          }

          while(read_code!=0){//if 0, then end of the file.
            read_code = read(input, line, MAX_PATH);
            line[read_code] = '\0';//to signal the end.
            write(output, line, strlen(line));//<--------------system call to write files.
          }
          override = 1;
          close(input);
          close(output);
          if (override == 1){
              break;
          }
      }else{
          printf("%s", "Override?(Y/N): ");//checks if it is overwritten
          getline(&answer,&lenght,stdin);
          if(strcmp(answer, "Y\n") == 0 || strcmp(answer, "y\n") == 0){
              unlink(salida);//delete file first
          }else{
              break;
          }
      }
    }

    free(answer);
    free(line);
    free(entrada);
    free(salida);


  return 0;
}
