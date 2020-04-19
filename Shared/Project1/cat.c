#include <stdio.h>
#include <stdlib.h>//standar libr
#include <unistd.h>
#include <fcntl.h>//for open
#include <string.h>//for string
#include <sys/stat.h>//check if file is there
#include <errno.h>
#include "addons.h"
#define MAX_PATH 260

struct stat st = {0};

int main(){

  char *entrada = char_string(MAX_PATH);
  strcpy(entrada, "input.c");

  int read_code = -1;
  char* line = char_string(MAX_PATH);
  if (stat(entrada, &st) != -1){
      // needs to check that exists.
        int input = open(entrada, O_RDONLY);//source
        if (input < 0){//checker
            printf("Error opening '%s': %s\n",entrada, strerror(errno));
            exit(1);
        }
        while(read_code!=0){//if 0, then end of the file.
          read_code = read(input, line, MAX_PATH);
          line[read_code] = '\0';//to signal the end.
          printf("%s\n",line);
        }
        close(input);
  }else{
      printf("%s","File doesn't exists.\n");//print statement that indicates the file is not found. It's not used for debugging but as an alert for the program itself.
  }
    free(line);
    free(entrada);
  return 0;
}
