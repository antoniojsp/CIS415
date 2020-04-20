#include <stdio.h>
#include "command.h"
#include "addons.h"
#include <string.h>
#define MAX_PATH 260
int main(){

  //listDir();
  //showCurrentDir();
  char* nombre = char_string(MAX_PATH);
  strcpy(nombre,"ll");
  makeDir(nombre);
  return 0;
}
