/*
* Description: Extracting token from a command line. We can use this as part of the command line interface in project 1.
*
* Author: Antonio Silva Paucar
*
* Date: 4/10/20
*
* Notes:
* 1. 1. it pass valgrind without any leak but for some reason I cannot generate a log. It has the desire effect.
*/

/*-------------------------Preprocessor Directives---------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500//number of characteres
#define TOKEN_LIST 500// number of tokens per command

/*---------------------------------------------------------------------------*/

/*-----------------------------Program Main----------------------------------*/
int main() {

		/* Main Function Variables */
		int exit_loop = 0;// value to exit loop.
		/* Allocate memory for the input buffer. */
		//malloc array of strings to gold
		char **list;// holds the words part of the line, array of string
		list = (char**)calloc(TOKEN_LIST,sizeof(char*));
		for(int i = 0; i < BUFFER_SIZE; i++) {
		  list[i] = (char*)calloc(BUFFER_SIZE,sizeof(char));
		}
		if (list == NULL)// check if it's ok
		{
			printf("FAIL");
			exit(1);
		}

		char *line_command;// command that it is input
		size_t size = BUFFER_SIZE;//size of allocation
		line_command = (char*)calloc(size,sizeof(char));//allocation by malloc and size.
		if (line_command == NULL)// check if it's ok
		{
			printf("FAIL");
			exit(1);
		}
		char *line =line_command;

		char *parts;//hold one token at the time.
		parts = (char*)calloc(100,sizeof(char));//allocation by malloc and size.
		char *parte= parts;//we use this pointer to iterate since if we change the position of the pointer, we later cannot free its memory

		/*main run loop*/
		/* Print >>> then get the input string */
		/* Tokenize the input string */
		/* Display each token */
		/* If the user entered <exit> then exit the loop */

		while (exit_loop == 0){//checks for exit command
			printf(">>>");
			line = line_command;
			getline(&line_command, &size, stdin);//input the  complete line.
			if(strcmp(line_command,"exit\n") == 0){// opttion for exit. It exists the loop and free memory.
				// perform a loop to release each pointer
				exit_loop = 1;
			}
			else if((strcmp(line_command,"\n"))==0){//check for empty lines.
					printf("%s","");
			}
			else{
					int k = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
					printf("\n");
					while ((parte = strtok_r(line, " ", &line))){//extract tokens and put into the array of strings.
						strcpy(list[k],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
						k+=1;
					}

					for(int i = 0; i<k; i++){//print the array.
						printf("T%d: %s",i,list[i]);
						if (i!=k-1)
							printf("\n");
					}
			}
		}

		for(int i = 0; i<BUFFER_SIZE; i++){
			free(list[i]);
		}
		free(list);
		free(line_command);
		free(parts);
	return 0;
}
/*-----------------------------Program End-----------------------------------*/
