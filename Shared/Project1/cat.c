

//ls
#include <stdio.h>
#include <dirent.h>// for the structure struc.
#include <stdlib.h>//for callo
#include <string.h>//for strcpy
#include <errno.h>//error
#include <unistd.h>//getcwd()
#include <sys/types.h>//
#include <sys/stat.h>//check if file is there
#include <errno.h>//errors codes
#include <fcntl.h>//for open
#include "addons.h" //for free memory

char* extract_name(char* name){

  char** token = array_2d(20, 100);
  char* parts = char_string(100);//divided by ;
  char* parte = parts;
  char* temp = char_string(100);
  strcpy(temp,name);
  char* temporal = temp;
  char* result = char_string(100);
  int number_tokens = 0;//to know the lenght of parts in the address
  while ((parte = strtok_r(temporal, "/", &temporal))){//extract tokens and put into the array of strings.
    strcpy(token[number_tokens],parte);
    number_tokens+=1;
  }
  strcpy(result,token[number_tokens-1]);// the last part of the token is the name of the line.
  free(parts);
  free(temp);
  free_double(token,20);

  return result;
}

int main(){
  int read_code = -1;
  char* line = char_string(200);
  char* result;

  char* name = char_string(100);
  strcpy(name,"../input.txt" );
  result = extract_name(name);
  printf("%s\n", result);
  int input = open(name, O_RDONLY);//source
  if (input < 0){//checker
      printf("%s\n","No imput." );
  }

  while(read_code!=0){//if 0, then end of the file.
    read_code = read(input, line, 200);
    line[read_code] = '\0';//to signal the end.
    printf("%s\n",line );
  }

  free(name);
  close(input);
  free(line);
  free(result);


  return 0;
}
