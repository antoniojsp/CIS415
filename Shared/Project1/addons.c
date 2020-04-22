#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "addons.h"
#define MAX_PATH 260//for sunir fuction. Max number of char a path can have
#define BUFFER_LENGHT 200
#define LISTA_COMANDOS 9
#define ARCHIVO 30

void free_double(char **array, int size){
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

char* sunir(int mode, char* name){// name can be the name of the folder to creat or the path where to add.
    char *slash = char_string(MAX_PATH);
    strcpy(slash, "/");
    char* dot = char_string(MAX_PATH);
    strcpy(dot,".");
    char* path = char_string(MAX_PATH);//path
    char* result = char_string(MAX_PATH);//path
    getcwd(path, MAX_PATH);//system call for path

    switch(mode){
      case 1:// add "./" + "name"
          strncat(dot,"/",MAX_PATH);
          strncat(dot,name,MAX_PATH);
          strncat(result, dot, MAX_PATH);
          break;
      case 2:// add "/" + path + "/name"
          strncat(path, "/", MAX_PATH);
          strncat(path,name,MAX_PATH);
          strncat(result, path, MAX_PATH);
          break;
      case 3:
          strncat(slash, name, MAX_PATH);
          strncat(result, slash, MAX_PATH);
          break;
    }

    free(path);
    free(dot);
    free(slash);
    return result;
}

char* char_string(int size){
    return (char*)calloc(size,sizeof(char));
}

char** array_2d(int size, int buffer)
{
	char** array = (char**)calloc(size,sizeof(char*));
	for(size_t i = 0; i < size; i++)
	{
			array[i] = (char*)calloc(buffer,sizeof(char));
	}
	return array;
}

int calls(char** list, int size){

    char** list_init = array_2d(MAX_PATH, BUFFER_LENGHT);
    strcpy(list_init[0],"ls\0");
    strcpy(list_init[1],"pwd\0");
    strcpy(list_init[2],"mkdir\0");
    strcpy(list_init[3],"cd\0");
    strcpy(list_init[4],"cp\0");
    strcpy(list_init[5],"mv\0");
    strcpy(list_init[6],"rm\0");
    strcpy(list_init[7],"cat\0");
    strcpy(list_init[8],"exit\0");

    char** list_rest = array_2d(MAX_PATH, BUFFER_LENGHT);
    strcpy(list_rest[0],"ls\n");
    strcpy(list_rest[1],"pwd\n");
    strcpy(list_rest[2],"mkdir\n");
    strcpy(list_rest[3],"cd\n");
    strcpy(list_rest[4],"cp\n");
    strcpy(list_rest[5],"mv\n");
    strcpy(list_rest[6],"rm\n");
    strcpy(list_rest[7],"cat\n");
    strcpy(list_rest[8],"exit\n");

    int resultados[LISTA_COMANDOS] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < size; i++){
        for (int j = 0; j < LISTA_COMANDOS; j++) {
          if(strcmp(list[i],list_init[j]) == 0 || strcmp(list[i],list_rest[j]) == 0){
            resultados[j]++;
          }
        }
    }
    int suma = 0;
    for (size_t i = 0; i < LISTA_COMANDOS; i++) {
        suma+=resultados[i];
    }

    free_double(list_init, MAX_PATH);
    free_double(list_rest, MAX_PATH);

    return suma;
}

char* extract_name(char* name){//when we ewnter "." we indicate that the copy is to the current directory. Extract the name of the file from the source.

  char** token = array_2d(ARCHIVO, BUFFER_LENGHT);
  char* parts = char_string(BUFFER_LENGHT);//divided by ;
  char* parte = parts;
  char* temp = char_string(BUFFER_LENGHT);
  strcpy(temp,name);
  char* temporal = temp;
  char* result = char_string(BUFFER_LENGHT);
  int number_tokens = 0;//to know the lenght of parts in the address
  while ((parte = strtok_r(temporal, "/", &temporal))){//extract tokens and put into the array of strings.
    strcpy(token[number_tokens],parte);
    number_tokens+=1;
  }
  strcpy(result,token[number_tokens-1]);// the last part of the token is the name of the line.
  free(parts);
  free(temp);
  free_double(token,ARCHIVO);

  return result;
}
