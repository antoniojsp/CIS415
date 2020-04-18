#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAX_PATH 260//max number of char allowed for directories path

struct stat st = {0};

int main(){

    char dot[MAX_PATH] = ".";//dot to add in front of the folder to create
    char slash[MAX_PATH] ="/";
    char folder[MAX_PATH] = "hola";//temp name of the folder
    char path[MAX_PATH];
    getcwd(path, sizeof(path));//system call for path

    char temp[MAX_PATH];//holds the path to the destination
    strcpy(temp,strncat(path, strncat(slash,folder,MAX_PATH), MAX_PATH));//check if exist.
    printf("%s\n",temp );
    char destination[MAX_PATH];
    strcpy(destination, strncat(dot,strncat(slash,folder,MAX_PATH),MAX_PATH));
    printf("%s\n",destination);

    if (stat(temp, &st) == -1) {
      mkdir(destination, 0700);
    }
    else{
      printf("%s\n","error" );
    }
    return 0;
}
