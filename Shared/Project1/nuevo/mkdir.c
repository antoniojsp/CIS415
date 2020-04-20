#include <sys/types.h>
#include <sys/stat.h>//check if file is there
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "addons.h"//sunir()
#define MAX_PATH 260//max number of char allowed for directories path

struct stat st = {0};

int main(){

    char* nombre = char_string(MAX_PATH);
    strcpy(nombre, "nuevo1");
    char* pathway;// "/yarayara/yireyire/hola"
    char* folder;// "./hola"

    pathway = sunir(2, nombre);//sunir is a personalized string concant for paths.
    //char* ruta = pathway;
    folder = sunir(1, nombre);
    //char* folder = carpeta;

    if (stat(pathway, &st) == -1) {
        mkdir(folder, 0700);
    }
    else{
      printf("%s\n","Folder already exists. Choose another name." );//not for debugging but part of the program.
      free(nombre);
      free(pathway);
      free(folder);
      exit(0);//maybe change
    }

    free(nombre);
    free(pathway);
    free(folder);

    return 0;
}
