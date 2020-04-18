#include <stdlib.h>
//define for ls.c

void free_double(char **array, int size){
    for (size_t i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}
