/*
* Description: Extracting token from a command line. We can use this as part of the command line interface in project 1.
*
* Author: Antonio Silva Paucar
*
* Date: 4/10/20
*
* Notes:
* 1. it pass valgrind without any leak but for some reason I cannot generate a log. it has the desire effect.
i could have printed the answer directly but I chosed to create an extra array to storage the inputs to be able to reuse this code in the future.
*/

/*-------------------------Preprocessor Directives---------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 500//number of characteres
#define TOKEN_LIST 500// number of tokens per command
/*---------------------------------------------------------------------------*/

/*-----------------------------Program Main----------------------------------*/
int main(int argc, char *argv[]) {// gets character from command line

		/* Main Function Variables */
		int exit_loop = 0;// value to exit loop.
		//char exit_command[10] = "exit\n";// command that invoke the exit_loop
		/* Allocate memory for the input buffer. */
		char **list;// holds the words part of the line
		//malloc array of strings.
		list = (char**)calloc(TOKEN_LIST,sizeof(char*));//hold parts of the commands
		for(int i = 0; i < TOKEN_LIST; i++) {
		  list[i] = (char*)calloc(BUFFER_SIZE,sizeof(char));//size of character
		}

		char *com = (char*)calloc(BUFFER_SIZE,sizeof(char));//allocation by malloc and size.
		char *communication = com;// we use this pointer to be able to delete *com later since if we iterate the pointer with memory allocation, we could not delete later

		char *parts = (char*)calloc(BUFFER_SIZE,sizeof(char));;///
		char *parte = parts;
		//reader
		char buffer[BUFFER_SIZE]; //hold a line
		char **lista = (char**)calloc(TOKEN_LIST,sizeof(char*));//hold lines in file
		for(int i = 0; i < BUFFER_SIZE; i++) {
		  lista[i] = (char*)calloc(BUFFER_SIZE,sizeof(char));
		}
		//file reader
		FILE *file_reader = fopen(argv[1], "r");
		if (file_reader == NULL){// if no input.txt found
			printf("Can't find input file. Closing\n");
			exit(1);
		}

		int j=0;
		while(fgets(buffer,TOKEN_LIST-1, file_reader) != NULL){
					strcpy(lista[j],buffer);
				j+=1;
		}

		int number_loops = 0;
		int k = 0;// for TX


		while (number_loops < j){//checks for exit command
			communication = com;
			communication = lista[number_loops];

			if(strcmp(communication,"exit\n") == 0){// if exit
				exit_loop = 1;
			}
			//else if((strcmp(communication,"\n"))==0){ //if empty
		//			printf("%s","");
			//}
			else{ //if command.
					while ((parte = strtok_r(communication, " ", &communication))){//extract files and put into the array of strings.
						strcpy(list[k],parte);// copy to an array of strings.
						k+=1;
					}
					number_loops+=1;
			}
		}

		FILE *writer_file = fopen("output.txt", "w");
		if (writer_file == NULL){
			printf("Fail to open output.\n");
			exit(1); //fail to load file
		}

		int  p = 0;
		for(int i = 0; i<k; i++){//print the array.
			fprintf(writer_file, "T%d: %s\n",p, list[i]);
			p+=1;
			if((list[i][strlen(list[i])-1]-'\n')==0)
				p = 0;

		}

		if (writer_file == NULL){
			printf("ERROR IN OUTPUT!.\n");
			exit(1);
		}

		fclose(writer_file);// close reader and writer
		fclose(file_reader);

		for(int i = 0; i<100; i++)
				free(list[i]);
		free(list);

		for(int i = 0; i<100; i++)
				free(lista[i]);
		free(lista);


	return 0;
}
/*-----------------------------Program End-----------------------------------*/
