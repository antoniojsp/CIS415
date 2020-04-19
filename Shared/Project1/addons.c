#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>



#define MAX_PATH 260//for sunir fuction. Max number of char a path can have

void free_double(char **array, int size){
    for (size_t i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

void sunir(int mode, char* name, char* result){// name can be the name of the folder to creat or the path where to add.
    char slash[MAX_PATH] = "/";
    char dot[MAX_PATH] = ".";

    char path[MAX_PATH];//path
    getcwd(path, sizeof(path));//system call for path
    //if mode 1 then
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
}
