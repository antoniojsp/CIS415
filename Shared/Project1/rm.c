#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>//check if file is there
#include <unistd.h>
#include "addons.h"
#define MAX_PATH 260


struct stat st = {0};

int main(int argc, char* argv[]){

  char* temp =(char*)calloc(MAX_PATH,sizeof(char));
  sunir(1,argv[1],temp)

  if (stat(, &st) == -1) {
      printf("%s\n","remove" );
      //unlink("a.out");
      unlink(temp);
  }else{
      printf("%s\n","File doesn't exist." );
  }


}
