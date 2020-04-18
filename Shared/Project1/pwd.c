#include <unistd.h>
#include <stdio.h>
#define MAX_PATH 260//maximum number of char allowed for path

int main() {
   char path[MAX_PATH];
   getcwd(path, sizeof(path));//system call for path
   printf("Path: %s\n", path);
   return 0;
}
