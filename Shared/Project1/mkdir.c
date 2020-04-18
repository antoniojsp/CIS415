#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAX_PATH 260//max number of char allowed for directories path

struct stat st = {0};

void concat(int mode, char* name){// name can be the name of the folder to creat or the path where to add.

    char slash[MAX_PATH] = "/";
    char dot[MAX_PATH] = ".";
    //if mode 1 then
    switch(mode){
      case 1:
          
    }

}

int main(){

    char folder_name[MAX_PATH] = "./";//dot to add in front of the folder to create
    char argumento[MAX_PATH] = "hola";//temp name of the folder, VARIABLE PASS
    strncat(folder_name, argumento, MAX_PATH);//folder has the name of the folder to create.
    printf("%s\n", folder_name );

    //char path[MAX_PATH] ="/";
    char temp[MAX_PATH];
    getcwd(temp, sizeof(temp));//system call for path
    strncat(temp, folder_name, MAX_PATH);//path nopw is "/" + Path
    printf("%s\n", temp);
    char destination[MAX_PATH];



    if (stat(temp, &st) == -1) {
      mkdir(destination, 0700);
    }
    else{
      printf("%s\n","error" );
    }
    return 0;
}
