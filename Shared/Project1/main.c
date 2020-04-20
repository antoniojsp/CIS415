#include <stdio.h>
#include "command.h"
#include "addons.h"
#include <string.h>
#include <stdlib.h>//for callo
#define MAX_PATH 260
int main(){

  //listDir();
  //showCurrentDir();

  //char* nombre = char_string(MAX_PATH);
  //strcpy(nombre,"lla");
  //makeDir(nombre);

  //char* cambio = char_string(MAX_PATH);
  //strcpy(cambio,"..");
  //changeDir(cambio);

  /*char* sourcePath = char_string(MAX_PATH);
  char* destinationPath = char_string(MAX_PATH);
  strcpy(sourcePath, "texto.txt");
  strcpy(destinationPath, "./salida.txt");
  copyFile(sourcePath, destinationPath);
  free(sourcePath);
  free(destinationPath);*/

  /*char* sourcePath = char_string(MAX_PATH);
  char* destinationPath = char_string(MAX_PATH);
  strcpy(sourcePath, "salida.txt");
  strcpy(destinationPath,"/media/sf_CIS415/hola1.txt");
  moveFile(sourcePath,destinationPath); */
  /*
  char* filename = char_string(MAX_PATH);
  strcpy(filename, "texto.txt");
  deleteFile(filename);
  //free(sourcePath);*/

  char *filename = char_string(MAX_PATH);
  strcpy(filename, "cp.c");
  displayFile(filename);

  free(filename);

  return 0;
}
