#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> //for callo
#include <string.h> //for strcpy
#include "addons.h" //for free memory
#define MAX_DIR 100//max number of files listed
#define BUFFER 50//number of chars

int main(){
    char** dir = (char**)calloc(MAX_DIR,sizeof(char*));//to save the results of the call
    for (size_t i = 0; i < MAX_DIR; i++) {
        dir[i] = (char*)calloc(BUFFER, sizeof(char));
    }

    struct dirent *structure;
    DIR *directory = opendir(".");
    if (directory == NULL){//checker
        exit(1);//for bad allocation. Terminate
    }
    int k = 0;//to iterate dir and also to know the number of elements in the directory for printing
    while ((structure = readdir(directory)) != NULL){
        char temp[BUFFER];
        char* pointy = temp;
        strcpy(pointy, structure->d_name);
        strcpy(dir[k],temp);
        k+=1;
    }

    for (size_t i = 0; i < k; i++) {//print content
        printf("%s\n", dir[i]);
    }

    free_double(dir, MAX_DIR);
    closedir(directory);
    return 0;
}
