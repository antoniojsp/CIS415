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

      char* line_command = NULL;
      char* linea = char_string(BUFFER);
      char* parts = char_string(BUFFER);//divided by ;
      char* parte = parts;

      char* pieza = char_string(TOKEN_BUFFER);
      size_t size = BUFFER;

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

          for (int i = 0; i < number_commands; i++) {
                //printf("%d\n", i);
                char** token = array_2d(LIST_INPUT, BUFFER);
                char* temp = char_string(BUFFER);
                strcpy(temp,list[i]);
                char* temporal = temp;
                //printf("%s\n",temporal);

                int k = 0;
                while ((parte = strtok_r(temporal, " ", &temporal))){//extract tokens and put into the array of strings.
                  strcpy(token[k],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
                  k+=1;
                }
    /*            for (size_t h = 0; h < k; h++) {
                  printf("%s\n", token[h]);
                }*/

                if(strcmp(token[0],"exit\n") == 0 || strcmp(token[0],"exit\0") == 0){
                    if(strcmp(token[1],"\0") == 0)
                      exit_loop = 1;
                    else{
                      printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                    }
                }
                else if((strcmp(line_command,"\n"))==0){//check for empty lines.
                    printf("%s","");
                }
                else if(strcmp(token[0],"ls\n") == 0 || strcmp(token[0],"ls\0") == 0 ){//check for empty lines.
                  if(strcmp(token[1],"\0") == 0)
                    listDir();
                  else{
                    printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                  }
                }
                else if(strcmp(token[0],"pwd\n") == 0 || strcmp(token[0],"pwd\0") == 0 ){//check for empty lines.
                  if(strcmp(token[1],"\0") == 0)
                    showCurrentDir();
                  else{
                    printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                  }
                }

                else if(strcmp(token[0],"mkdir\n") == 0 || strcmp(token[0],"mkdir\0") == 0 ){//check for empty lines.
                  if(strcmp(token[1],"\n") != 0 && strcmp(token[2],"\0") != 0){
                    printf("%s\n","Too many arguments." );
                  }
                  else if(strcmp(token[1],"\0") != 0)
                    makeDir(token[1]);
                  else{
                    printf("Error!: Unsupported parameter for command: %s\n",list[0]);
                  }
                }

                else if((strcmp(strcmp(token[0],"cd\n") == 0 || strcmp(token[0],"cd\0") == 0){//check for empty lines.
                    printf("%s","3");
                }/*
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
*/
                else{//check for empty lines.

                    printf("Error! Unrecognized command: %s\n", token[0]);
                }
                free_double(token, LIST_INPUT);
                free(temp);
        }


      }


      free_double(list_commands, COMMAND_LIST);
      free_double(list, LIST_INPUT);
      free(line_command);
      free(parts);

  return 0;
}
