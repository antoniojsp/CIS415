#include <stdio.h>
#include "command.h"
#include "addons.h"
#include <string.h>
#include <stdlib.h>//for callo
#define COMMAND_LIST 20//list of commads avalaible
#define LIST_INPUT 50//number of tokens
#define BUFFER 100//how many characters per line
#define TOKEN_BUFFER 20

int main(){

      int exit_loop = 0;
      char** list_commands = array_2d(COMMAND_LIST,BUFFER);
      char** list = array_2d(LIST_INPUT,BUFFER);
      char** token = array_2d(LIST_INPUT, BUFFER);
      char* line_command = NULL;
      char* linea = char_string(BUFFER);
      char* parts = char_string(BUFFER);//divided by ;
      char* parte = parts;
      char* pieza = char_string(TOKEN_BUFFER);
      size_t size = BUFFER;

      strcpy(list_commands[0],"ls\n");
      strcpy(list_commands[1],"pwd\n");
      strcpy(list_commands[2],"mkdir\n");
      strcpy(list_commands[3],"cd\n");
      strcpy(list_commands[4],"cp\n");
      strcpy(list_commands[5],"mv\n");
      strcpy(list_commands[6],"rm\n");
      strcpy(list_commands[7],"cat\n");
      strcpy(list_commands[8],"exit\n");

      while(exit_loop == 0){

          printf("%s",">>>");

          getline(&line_command, &size, stdin);
          strcpy(linea,line_command);
          char*line = linea;

          int number_commands = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
          while ((parte = strtok_r(line, ";", &line))){//extract tokens and put into the array of strings.
            strcpy(list[number_commands],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
            number_commands+=1;
          }

          for (size_t i = 0; i < number_commands; i++) {

                char* temp = char_string(BUFFER);
                strcpy(temp,list[i]);
                printf("%s\n",temp);
/*
                int k = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
                while ((parte = strtok_r(temp, " ", &line))){//extract tokens and put into the array of strings.
                  strcpy(list[k],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
                  k+=1;
                }

                if(strcmp(list[0],list_commands[8]) == 0){
                    if(strcmp(list[1],"\0") == 0)
                      exit_loop = 1;
                    else{
                      printf("Error!: Unrecognized command: %s",list[0]);
                    }
                }


                else if(strcmp(list[0],list_commands[0]) == 0 ){//check for empty lines.
                    listDir();
                }
                else if((strcmp(list[0],list_commands[1])) == 0){//check for empty lines.
                    printf("%s","1");
                }
                else if((strcmp(list[0],list_commands[2])) == 0){//check for empty lines.
                    printf("%s","2");
                }
                else if((strcmp(list[0],list_commands[3])) == 0){//check for empty lines.
                    printf("%s","3");
                }
                else if((strcmp(list[0],list_commands[4])) == 0){//check for empty lines.
                    printf("%s","4");
                }
                else if((strcmp(list[0],list_commands[5])) == 0){//check for empty lines.
                    printf("%s","5");
                }
                else if((strcmp(list[0],list_commands[6])) == 0){//check for empty lines.
                    printf("%s","6");
                }
                else if((strcmp(list[0],list_commands[7])) == 0){//check for empty lines.
                    printf("%s","7");
                }

                else{//check for empty lines.
                    printf("%s","9");
                }
*/
                free(temp);
        }


      }


      free_double(list_commands, COMMAND_LIST);
      free(line_command);
      free(parts);

  return 0;
}
