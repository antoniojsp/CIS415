#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  int contador = 0;
  for (size_t i = 0; i < 12; i++) {
    printf("Second Test Program. Time: %d\n", contador);
    // printf("PID %d\n", getpid());
    contador++;
    sleep(1);
  }
  printf("%s\n","Done with second test program. Exit!" );

  return 0;
}
