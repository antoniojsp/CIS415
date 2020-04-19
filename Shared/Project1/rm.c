#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>//check if file is there
#include <unistd.h>
#include <string.h>//string copy
#include <errno.h>
#include "addons.h"

#define MAX_PATH 260

struct stat st = {0};

int main(){

  char* file = char_string(MAX_PATH);;
  strcpy(file,"maria");//entry point
  //  "/media/sf_CIS415/hola1.txt"-> how to enter for differnent path than current.
  //  hola.txt   -> current directory
  if(unlink(file) == 0){

  }else{
      printf("Error with '%s': %s\n",file, strerror(errno));//Show errors of why the file is not deleted. If it doesn't exists it will say it.
  }

  return 0;


}
