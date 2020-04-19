#include <stdio.h>
#include <dirent.h>// for the structure struc.
#include <stdlib.h>//for callo
#include <string.h>//for strcpy
#include <errno.h>//error
#include "addons.h" //for free memory
#define MAX_DIR 100//max number of files listed
#define BUFFER 50//number of chars

//No leaks!
int main(){
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
    return 0;
}
