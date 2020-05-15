#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){

    int contador = 0;
    for (int i = 0; i < atoi(argv[1]); i++) {
      printf("First test program. Time: %d\n", contador);
      sleep(1);
      contador++;
    }
    printf("%s\n","Done with first test program. Exit!" );
    return 0;
}
