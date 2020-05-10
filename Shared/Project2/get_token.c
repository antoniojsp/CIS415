#include <stdio.h>//base
#include <string.h>// for strcpy and demas
#include <stdlib.h>
#include "utilities.h"
#define NUMBER_LINES 50
#define BUFFER_LENGTH 50//number of char per line in input
#define TOKENS_NUMBER 10//number of parameters per line
#define PARAMETER_LENGTH 40//number of character per paramaenter

int main(int argc, char** argv){

  char** lista = char_two(NUMBER_LINES, BUFFER_LENGTH);// linea de comandos
  int lines = read_file(argv, lista);// lineas enteras
  char **tokens= char_two(TOKENS_NUMBER, PARAMETER_LENGTH);
  char* parts = char_one(TOKENS_NUMBER);// parts of the token
  char* parte = parts;
  char* linea = char_one(BUFFER_LENGTH);//save a line at the time

  // printf("%d\n",lines );

  for (int i = 0; i < lines; i++) {
      strcpy(linea, lista[i]);
      int numero = get_tokens(lista[i],tokens);
      for (size_t i = 0; i < numero; i++) {
        /* code */
        printf("%s\n",tokens[i]);
      }
  }

  free(parts);
  free(linea);
  free2d(tokens, TOKENS_NUMBER);
  free2d(lista, NUMBER_LINES);
  return 0;
}
