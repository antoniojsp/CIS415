#include<stdio.h>
#include<signal.h>
#include<wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid[5];

    for (int i = 0; i < 5; i++) {
        pid_t pd = fork();
        if(pd == 0){
           printf("Hola\n");
           exit(0);
        }
    }
    printf("%s\n","Aqui" );
    for(int j = 0; j < 5; j++){
         wait(0);
    }

    return 0;

}
