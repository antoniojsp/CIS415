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
  char* temp = char_string(MAX_PATH);

  strcpy(file,"/media/sf_CIS415/Shared/hola1.txt");
  temp = sunir(3,file);
  //  "/media/sf_CIS415/hola1.txt"-> how to enter for differnent path than current.
  if(unlink("/") == 0){
      printf("%s\n","remove" );
  }else{
      printf("Error with '%s': %s\n",file, strerror(errno));
  }
  /*
  if (stat(temp, &st) == -1) {
      printf("%s\n","remove" );
      //unlink("a.out");
      unlink(file);
  }else{
      printf("%s\n","File doesn't exist." );
  }*/

  return 0;


}
