#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

#define BUFFER 1000
#define TOKEN 100
#define NUMBER 100


int main(){

    char *reading = char_one(BUFFER);
    char* slot = char_one(BUFFER);//save a line at the time
    char** tokens = char_two(NUMBER, TOKEN);
    char* parts = char_one(TOKEN);//parts save
    char* parte = parts;
    char* section = char_one(BUFFER);//copy from line, la linea
    char* temp =  slot;

    FILE *proc;

    proc = fopen ("/proc/8712/stat", "r");
    if (proc == NULL){
        exit (1);
    }else{

        while( fgets ( reading, BUFFER, proc ) != NULL )
        {
            strcpy(slot,reading) ;
            // pr`intf("%s\n", slot );
        }

        int number_parameter = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
        while ((parte = strtok_r(temp, " ", &temp))){//extract tokens and put into the array of strings.
          strcpy(tokens[number_parameter],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
          number_parameter+=1;
        }
        printf("%d\n",number_parameter );
        for (int i = 0; i < number_parameter; i++) {
            printf("%d: %s\n",i,tokens[i] );
        }

        fclose(proc) ;

    }

  return 0;
}
