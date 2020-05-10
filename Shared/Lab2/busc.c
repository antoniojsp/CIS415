#include <stdio.h>
#include <addons.h>

int calls(char* list){

    char** list_commands = array_2d(MAX_PATH, BUFFER_LENGHT);
    strcpy(list_commands[0],"ls\0");
    strcpy(list_commands[1],"pwd\0");
    strcpy(list_commands[2],"mkdir\0");
    strcpy(list_commands[3],"cd\0");
    strcpy(list_commands[4],"cp\0");
    strcpy(list_commands[5],"mv\0");
    strcpy(list_commands[6],"rm\0");
    strcpy(list_commands[7],"cat\0");
    strcpy(list_commands[8],"exit\0");

    for (size_t i = 0; i < count; i++) {
      if(strcmp(list,list_commands[i])==0)
      {

      }
    }

}

int main(){



  return 0;
}
