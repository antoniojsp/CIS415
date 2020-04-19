#include <stdio.h>
#include <stdlib.h>//standar libr
#include <unistd.h>
#include <fcntl.h>//for open
#include<string.h>
#include <sys/stat.h>//check if file is there

#define MAX_LENGHT 260

struct stat st = {0};


int main(int argc, char *argv[]){

  //printf("%s\n %s\n",argv[1],argv[2] );
  char* line =(char*)calloc(MAX_LENGHT,sizeof(char));

  int input = open(argv[1], O_RDONLY, 0644);//source
  if (input < 0) {//checker
      exit(1);
  }
//media/sf_CIS415/Shared/output.txt
  int output = open(argv[2], O_CREAT | O_WRONLY, 0644);//destination
  if (output < 0) {//checker
    exit(1);
  }

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 1;
  char answer[5];

  while (end_loop == 1){
    if (stat(argv[2], &st) == -1 || override == 1) {
        while(read_code!=0){//if 0, then end of the file.
          read_code = read(input, line, MAX_LENGHT);
          line[read_code] = '\0';//to signal the end.
          write(output, line, strlen(line));//<--------------system call to write files.
        }
        end_loop = 0;
    }else{
        printf("%s\n", "Override?" );
        scanf("%s\n",answer);
        if(strcmp(answer, "Yes\n") == 0){
          override = 1;
        }else{
          break;
        }
    }
  }
}
