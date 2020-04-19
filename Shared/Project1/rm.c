#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>//check if file is there
#include <unistd.h>
#include <string.h>//string copy
#include "addons.h"
#define MAX_PATH 260

struct stat st = {0};

int main(int argc, char* argv[]){

  char* file = (char*)calloc(MAX_PATH,sizeof(char));
  char* temp = (char*)calloc(MAX_PATH,sizeof(char));
  strcpy(file,argv[1]);
  sunir(3,file,temp);

  printf("%s\n",file );
  printf("%s\n", temp);
  if (stat(temp, &st) == -1) {
      printf("%s\n","remove" );
      //unlink("a.out");
      unlink(file);
  }else{
      printf("%s\n","File doesn't exist." );
  }


}
