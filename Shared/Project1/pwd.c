#include <unistd.h>//getcwd()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addons.h"
#define MAX_PATH 260//maximum number of char allowed for path
//no memory leaks!
int main() {
   char *path = char_string(MAX_PATH);//path of the file
   getcwd(path, MAX_PATH);//system call for path
   printf("Path: %s\n", path);
   free(path);
   return 0;
}
