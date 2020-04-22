#include <stdio.h>
#include "command.h"
#include "addons.h"
#include <string.h>
#include <stdlib.h>//for callo
#define COMMAND_LIST 20//list of commads avalaible
#define LIST_INPUT 50//number of tokens
#define BUFFER 100//how many characters per line
#define TOKEN_BUFFER 100
#define LINES 500//for the file reader. File MODE. It can accept up to 500 lines of instructions from the file.

int main(int argc, char* argv[]){
      int exit_loop = 0;
      char** list_commands = array_2d(COMMAND_LIST,BUFFER);
      char** list = array_2d(LIST_INPUT,BUFFER);

      char* line_command = NULL;
      char* linea = char_string(BUFFER);

      char* parts = char_string(BUFFER);//divided by ;
      char* parte = parts;

      char* pieza = char_string(TOKEN_BUFFER);
      size_t size = BUFFER;

      //FILE MODE
      char** file_mode = array_2d(LINES, BUFFER);
      char* modo = char_string(10);//
      //strcpy(modo, "-f");
      int lineas_file=0;
      if(argv[1]!=NULL){
          strcpy(modo, argv[1]);
      }else{
          strcpy(modo,"X");
      }

      if(strcmp(modo,"-f")==0){
          FILE *file_reader = fopen("input.txt", "r");
          if (file_reader == NULL){// if no input.txt found. The program will exit
            //exit(1);
          }

          char buffer[BUFFER];
          while(fgets(buffer,TOKEN_BUFFER, file_reader) != NULL){
                strcpy(file_mode[lineas_file],buffer);
              lineas_file+=1;
          }
          fclose(file_reader);
      }

    int modo_archivo = 0;// when -f is activated
    while(exit_loop == 0 || modo_archivo < lineas_file){
          printf("%s",">>>");
          if(strcmp(modo,"-f")==0){// argumentos
            strcpy(linea,file_mode[modo_archivo]);
            printf("%s",linea);
          }else{
            getline(&line_command, &size, stdin);
            strcpy(linea,line_command);
          }

          char*line = linea;
          int number_commands = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
          int separador_si = 0;
          while ((parte = strtok_r(line, ";", &line))){//extract tokens and put into the array of strings.
            strcpy(list[number_commands],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
            separador_si++;
            number_commands+=1;
          }

          for (int i = 0; i < number_commands; i++) {
                char** token = array_2d(LIST_INPUT, BUFFER);
                char* temp = char_string(BUFFER);
                strcpy(temp,list[i]);
                char* temporal = temp;

                int number_tokens = 0;
                while ((parte = strtok_r(temporal, " ", &temporal))){//extract tokens and put into the array of strings.
                  strcpy(token[number_tokens],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
                  number_tokens+=1;
                }

                int control = calls(token,number_tokens);//function  that checks control code. If has 1 means there is only one command in the line, more than 1 is a code control error.
                if (i == number_commands-1 && number_tokens > 2){// cleans the string if it is needed. The last character may interfere with the code.
                    token[2][strlen(token[2])-1] = 0;
                }
                else if (i == number_commands-1 && number_tokens > 1){// cleans the string if it is needed. The last character may interfere with the code.
                    token[1][strlen(token[1])-1] = 0;
                }

                if(control == 1 || control == 0  ){
                    if(strcmp(token[0],"exit\n") == 0 || strcmp(token[0],"exit\0" ) == 0){
                        if(number_tokens == 1){
                          exit_loop = 1;
                        }
                        else{
                          printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                        }
                    }
                    else if((strcmp(token[0],"\n"))==0){//check for empty lines.
                        printf("%s","");
                    }

                    else if(strcmp(token[0],"ls\n") == 0 || strcmp(token[0],"ls\0") == 0){//check for empty lines.
                      if(number_tokens == 1)
                        listDir();
                      else{
                        printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                      }
                    }
                    else if((strcmp(token[0],"pwd\n") == 0 || strcmp(token[0],"pwd\0") == 0) && number_tokens < 2 ){//check for empty lines.
                      if(number_tokens == 1)
                      {
                        showCurrentDir();
                      }
                      else{
                        printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                      }
                    }
                    else if(strcmp(token[0],"mkdir\n") == 0 || strcmp(token[0],"mkdir\0") == 0){//check for empty lines.
                      if(number_tokens = 2){
                        makeDir(token[1]);
                      }
                      else{
                        printf("Error!: Unsupported parameter for command: %s\n",list[0]);
                      }
                    }

                    else if(strcmp(token[0],"cd\n") == 0 || strcmp(token[0],"cd\0") == 0){//check for empty lines.

                        if(number_tokens == 2){
                          changeDir(token[1]);
                        }
                        else{
                          printf("Error!: Unsupported parameter for command: %s\n",list[0]);
                        }
                    }

                    else if(strcmp(token[0],"cp\n") == 0 || strcmp(token[0],"cp\0")==0){//check for empty lines.
                      if(number_tokens == 3){
                        copyFile(token[1], token[2]);
                      }
                      else{
                        printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                      }
                    }

                    else if(strcmp(token[0],"mv\n") == 0 || strcmp(token[0],"mv\0") == 0){//check for empty lines.
                      if( number_tokens == 3){
                        moveFile(token[1], token[2]);
                      }
                      else{
                        printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                      }
                    }

                    else if(strcmp(token[0],"rm\n") == 0 || strcmp(token[0],"rm\0") == 0){//check for empty lines.

                      if(number_tokens == 2)
                        deleteFile(token[1]);
                      else{
                        printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                      }
                    }

                    else if(strcmp(token[0],"cat\n") == 0 || strcmp(token[0],"cat\0") == 0){//check for empty lines.

                      if(number_tokens == 2){
                          displayFile(token[1]);
                      }
                      else {
                        printf("Error!: Unsupported parameter for command: %s\n",token[0]);
                      }
                    }

                    else{//check for empty lines.
                        printf("Error! Unrecognized command: %s\n", token[0]);
                    }
              }
                else{
                    printf("Error! Incorrect syntax. No control codefound,\n");
                }
              free_double(token, LIST_INPUT);
              free(temp);
        }

        modo_archivo++;
        if(modo_archivo<lineas_file){
          exit_loop = 1;
        }

    }

    free_double(list_commands, COMMAND_LIST);
    free_double(list, LIST_INPUT);
    free(line_command);
    free(parts);
    free(linea);
    free(modo);
    free(pieza);

    free_double(file_mode,LINES);


  return 0;
}
