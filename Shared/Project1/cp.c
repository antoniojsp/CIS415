#include <stdio.h>
#include <stdlib.h>//standar libr
#include <unistd.h>
#include <fcntl.h>//for open
#include <string.h>//for string
#include <sys/stat.h>//check if file is there
#define MAX_LENGHT 260

struct stat st = {0};

int main(int argc, char *argv[]){

  char *entrada = (char*)calloc(MAX_LENGHT,sizeof(char));
  char *salida = (char*)calloc(MAX_LENGHT,sizeof(char));

  strcpy(entrada, argv[1]);
  strcpy(salida, argv[2]);

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;
  size_t lenght = 3;

  char* answer = (char*)calloc(lenght,sizeof(char));
  //char* answer = respuesta;
  char* line =(char*)calloc(MAX_LENGHT,sizeof(char));
  //char* line = linea;

  while(end_loop == 0){//checks if the file exists or no
      if (stat(salida, &st) == -1){
            int input = open(entrada, O_RDONLY);//source
            if (input < 0){//checker
                exit(1);
            }

            int output = open(salida, O_CREAT | O_WRONLY, 0644);//destination
            if (output < 0){//checker
              exit(1);
            }

            while(read_code!=0){//if 0, then end of the file.
              read_code = read(input, line, MAX_LENGHT);
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
