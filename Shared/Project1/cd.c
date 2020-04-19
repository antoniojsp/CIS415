
#include<stdio.h>
#include<unistd.h>
#include "addons.c"
#include <errno.h>
//no leak
#define MAX_PATH 260
int main()
{
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
