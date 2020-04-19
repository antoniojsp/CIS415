#include <sys/types.h>
#include <sys/stat.h>//check if file is there
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "addons.h"
#define MAX_PATH 260//max number of char allowed for directories path

struct stat st = {0};

int main(int argc, char *argv[]){

    char pathway[MAX_PATH];
    char* path = pathway;// "/yarayara/yireyire/hola"
    char folder[MAX_PATH];
    char* carpeta = folder;// "./hola"
    sunir(1, argv[1], pathway);
    sunir(2, argv[1], carpeta);

    if (stat(pathway, &st) == -1) {
      mkdir(carpeta, 0700);
    }
    else{
      exit(1);
    }
    return 0;
}
