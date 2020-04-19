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
  strcpy(entrada, argv[1]);

  int read_code = -1;
  char* line =(char*)calloc(MAX_LENGHT,sizeof(char));
  printf("%s\n",entrada );
  if (stat(entrada, &st) != -1){
      // needs to check that exists.
        int input = open(entrada, O_RDONLY);//source
        if (input < 0){//checker
            exit(1);
        }
        while(read_code!=0){//if 0, then end of the file.
          read_code = read(input, line, MAX_LENGHT);
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
