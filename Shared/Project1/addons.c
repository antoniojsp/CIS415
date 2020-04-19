#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "addons.h"
#define MAX_PATH 260//for sunir fuction. Max number of char a path can have

void free_double(char **array, int size){
    for (size_t i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

char* sunir(int mode, char* name){// name can be the name of the folder to creat or the path where to add.
    char *slash = char_string(MAX_PATH);
    strcpy(slash, "/");
    char* dot = char_string(MAX_PATH);
    strcpy(dot,".");
    char* path = char_string(MAX_PATH);//path
    char* result = char_string(MAX_PATH);//path
    getcwd(path, MAX_PATH);//system call for path
    
    switch(mode){
      case 1:// add "./" + "name"
          strncat(dot,"/",MAX_PATH);
          strncat(dot,name,MAX_PATH);
          strncat(result, dot, MAX_PATH);
          break;
      case 2:// add "/" + path + "/name"
          strncat(path, "/", MAX_PATH);
          strncat(path,name,MAX_PATH);
          strncat(result, path, MAX_PATH);
          break;
      case 3:
          strncat(slash, name, MAX_PATH);
          strncat(result, slash, MAX_PATH);
          break;
    }

    free(path);
    free(dot);
    free(slash);
    return result;
}

char* char_string(int size){
    return (char*)calloc(size,sizeof(char));
}
