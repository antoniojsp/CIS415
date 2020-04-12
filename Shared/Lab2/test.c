#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char hola[10] = "hola\n";
    //printf("%lu %c",strlen(hola),hola[strlen(hola)-1] );

    char last = hola[strlen(hola)-2];

    printf("%c", last);
    if ((last - '\n') == 0)
        printf("vacio");

    return 0;
}
