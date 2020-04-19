#include <stdio.h>
#include <stdlib.h>//standar libr
#include <unistd.h>
#include <fcntl.h>//for open
#include<string.h>//for string
#include <sys/stat.h>//check if file is there
#define MAX_LENGHT 260

struct stat st = {0};

int main(int argc, char *argv[]){

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;
  size_t lenght = 3;
  char* answer = (char*)calloc(lenght,sizeof(char));

  while(end_loop == 0){//checks if the file exists or no
      if (stat(argv[2], &st) == -1){
            char* line =(char*)calloc(MAX_LENGHT,sizeof(char));
            int input = open(argv[1], O_RDONLY);//source
            if (input < 0){//checker
                exit(1);
            }
          //media/sf_CIS415/Shared/output.txt
            int output = open(argv[2], O_CREAT | O_WRONLY, 0644);//destination
            if (output < 0){//checker
              exit(1);
            }
            while(read_code!=0){//if 0, then end of the file.
              read_code = read(input, line, MAX_LENGHT);
              line[read_code] = '\0';//to signal the end.
              write(output, line, strlen(line));//<--------------system call to write files.
            }
            override = 1;
            if (override == 1){
                break;
            }
      }else{
          printf("%s", "Override?(Y/N): " );
          getline(&answer,&lenght,stdin);
          if(strcmp(answer, "Y\n") == 0 || strcmp(answer, "y\n") == 0){
            unlink(argv[2]);//delete file first
          }else{
            break;
          }
      }
    }

  return 0;
}
