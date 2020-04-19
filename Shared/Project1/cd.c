
#include<stdio.h>
#include<unistd.h>
#define MAX_PATH 100
int main(int argc, char *argv[])
{
    char s[MAX_PATH];
    chdir(argv[1]);//change for variable
    printf("Moved to %s\n", getcwd(s, 100));//to verify, remove in the future.
    return 0;
}
