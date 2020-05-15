#include "utilities.h"
#include <stdlib.h>//calloc, malloc
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_LENGTH 50//number of char per line in input
#define TOKENS_NUMBER 50//number of parameters per line
#define PARAMETER_LENGTH 10//number of character per paramaenter

//delete 2d array strings
void free2d(char **array, int size){
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}//free 2d array
char* char_one(int size){
    return (char*)calloc(size,sizeof(char));
}//create one dimmension array char, one string
char** char_two(int size, int buffer){
	char** array = (char**)calloc(size,sizeof(char*));
	for(size_t i = 0; i < size; i++)
	{
			array[i] = (char*)calloc(buffer,sizeof(char));
	}
	return array;
}// create 2d array of char, strings
int read_file(char** file_name, char** lista){//read input file.

  FILE *file_reader = fopen(file_name[1], "r");
  if (file_reader == NULL){// if no input.txt found. The program will exit
    exit(1);
  }
  int lineas_file = 0;
  char buffer[BUFFER_LENGTH];
  while(fgets(buffer,BUFFER_LENGTH, file_reader) != NULL){
        strcpy(lista[lineas_file],buffer);
      lineas_file+=1;
   }
  fclose(file_reader);// fclose allowed for main.

  return lineas_file;
}

int get_tokens(char* line, char** tokens){
  char* parts = char_one(TOKENS_NUMBER);//parts save
  char* parte = parts;
  char* section = char_one(BUFFER_LENGTH);//copy from line, la linea
  strcpy(section, line);
  char* temp =  section;

  int number_parameter = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
  while ((parte = strtok_r(temp, " ", &temp))){//extract tokens and put into the array of strings.
    strcpy(tokens[number_parameter],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
    number_parameter+=1;
  }
  tokens[number_parameter-1][strlen(tokens[number_parameter-1])-1] = 0;//fix the last token introduced to
  free(parts);
  free(section);

  return number_parameter;

}

void back_timer(int sec){
  for (int i = 0; i < sec; i++) {
    printf("* In %d seconds.\n", (5 - i));
    sleep(1);
  }
}
