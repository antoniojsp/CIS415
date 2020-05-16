#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

#define BUFFER 1000
#define TOKEN 100
#define NUMBER 100
#define TEMPORAL 50
#define clrscr() printf("\e[1;1H\e[2J")

void  system_monitor(int pids)
{
    char* reading = char_one(BUFFER);
    char* mem = char_one(BUFFER);
    char* slot = char_one(BUFFER);//save a line at the time
    char** tokens = char_two(NUMBER, TOKEN);
    char* parts = char_one(TOKEN);//parts save
    char* parte = parts;
    char* section = char_one(BUFFER);//copy from line, la linea
    char* temp =  slot;
    char *linea = char_one(BUFFER);
    char** chicos = char_two(NUMBER,BUFFER);

    printf("%s\n"," ################### Part4 ################### " );

    clrscr();
    int a = pids;
    char* stri = char_one(BUFFER);
    //char stri[TEMPORAL];
    sprintf(stri, "%d", a);// gets the pdi

    strcpy(mem, "/proc/");
    strcat(mem, stri);
    strcat(mem, "/stat");
    FILE *proc = fopen (mem, "r");
    printf("Info of process with pdi number %d\n", pids);
    if (proc == NULL){
        exit (1);
    }else{

        while(fgets(reading, BUFFER, proc)!= NULL)
        {
            strcpy(slot,reading) ;
        }

        int number_parameter = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
        while ((parte = strtok_r(temp, " ", &temp))){//extract tokens and put into the array of strings.
          strcpy(tokens[number_parameter],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
          number_parameter+=1;
        }
        printf("PID: %s\n", tokens[0]);
        printf("File name: %s\n", tokens[1]);
        printf("State: %s\n", tokens[2]);
        printf("Priority: %s\n", tokens[17]);

    }

    fclose(proc);

    printf("\n");
    FILE *valores;
    char path[TEMPORAL];
    strcpy(mem,"ps -p ");
    strcat(mem, stri);
    strcpy(chicos[0],mem);
    strcat(chicos[0]," -o %mem");
    strcpy(chicos[1],mem);
    strcat(chicos[1]," -o %cpu");

    for (int i = 0; i < 2; i++) {
        valores = popen(chicos[i], "r");
        if (valores == NULL) {
          exit(1);
        }
        while (fgets(path, sizeof(path), valores) != NULL) {
          printf("%s", path);
        }
    }
    pclose(valores);

    printf("\n");
    FILE *io;
    char ruta[TEMPORAL];
    strcpy(mem,"cat /proc/");
    strcat(mem, stri);
    strcat(mem, "/io");
    io = popen(mem, "r");
    if (io == NULL) {
      exit(1);
    }
    while (fgets(ruta, sizeof(ruta), io) != NULL) {
      printf("%s", ruta);
    }
    pclose(io);



  free(stri);
  free(reading);
  free(slot);
  free(parts);
  free(section);
  free2d(tokens, NUMBER);
  free(linea);
  free(mem);
  free2d(chicos, NUMBER);

}
