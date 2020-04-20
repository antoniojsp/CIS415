//ls
#include <stdio.h>
#include <dirent.h>// for the structure struc.
#include <stdlib.h>//for callo
#include <string.h>//for strcpy
#include <errno.h>//error
#include "addons.h" //for free memory
#define MAX_DIR 100//max number of files listed
#define BUFFER 50//number of chars
//pwd
#include <unistd.h>//getcwd()
#define MAX_PATH 260//maximum number of char allowed for path
//mkdir
#include <sys/types.h>
#include <sys/stat.h>//check if file is there
//changeDir

#include <errno.h>


struct stat st = {0};
//No leaks!
void listDir()
{
    struct dirent *structure;
    DIR *directory = opendir("./");//system call opendir for checking directories. It returns a pointer.
    if (directory == NULL){//checker
        printf("%s\n", strerror(errno));
        exit(1);//for bad allocation. Terminate
    }
    while ((structure = readdir(directory)) != NULL){//
        printf("%s\n", structure->d_name);//printing files in the directory. d_name hint from the project1 description.
    }
    closedir(directory);
}

void showCurrentDir()
{
   char *path = char_string(MAX_PATH);//path of the file
   getcwd(path, MAX_PATH);//system call for path
   printf("Path: %s\n", path);
   free(path);
}

void makeDir(char* nombre){

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

    //free(nombre);
    free(pathway);
    free(folder);
}

void changeDir(char *dirName){
    char *move = char_string(MAX_PATH);
    strcpy(move, "nuevo" );
    if(chdir(move) == 0){//change for variable http://man7.org/linux/man-pages/man2/chdir.2.html
      //chdir return 0 if ok or 1 if any error is found. errno
      printf("Moved to %s\n", getcwd(move, MAX_PATH));//confirmation for moving. NO DEBBUGING.
    }else{
      printf("Unable to access %s: %s\n",move, strerror(errno));//report error
    }
    free(move);
    return 0;
}
