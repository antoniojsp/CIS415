/*
* Description: Line command and execute lfcat for Lab3
*
* Author: Antonio Silva Paucar
*
* Date: 4/17/20
*
* Notes:
* 1. All functions implemented and zero leaks.
*/

/*-------------------------Preprocessor Directives---------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "addons.h"

#define BUFFER_SIZE 500//number of characteres
#define TOKEN_LIST 500// number of tokens per command
#define LIST_COMMANDS 30
#define SIZE_TOKEN 50

int main(){

		/* Main Function Variables */
		int exit_loop = 0;// value to exit loop.

		char **list = array_2d(LIST_COMMANDS, BUFFER_SIZE);// holds the words part of the line, array of string


		//start of list of commands avalaible.
		char list_commands[20] = "lfcat\n";//command for lab3
		char *comandos = list_commands;
		//printf("%s", list_commands[0]);
		//end of list of commands


		char *line_command;// command that it is input
		size_t size = BUFFER_SIZE;//size of allocation
		line_command = (char*)calloc(size,sizeof(char));//allocation by malloc and size.
		if (line_command == NULL)// check if it's ok
		{
			exit(1);
		}

		char *line = line_command;

		char *parts;//hold one token at the time.
		parts = (char*)calloc(SIZE_TOKEN,sizeof(char));//allocation by malloc and size.
		if (parts == NULL)// check if it's ok
		{
			exit(1);
		}
		char *parte= parts;//we use this pointer to iterate since if we change the position of the pointer, we later cannot free its memory



		char** command_list = array_2d(TOKEN_LIST, BUFFER_SIZE);//hold all the commands.
		command_list[0] = "ls\n";
		command_list[1] = "pwd\n";
		command_list[2] = "mkdir\n";
		command_list[3] = "cd\n";
		command_list[4] = "cp\n";
		command_list[5] = "mv\n";
		command_list[6] = "rm\n";
		command_list[7] = "cat\n";
		command_list[8] = "-f\n";






		while (exit_loop == 0){//checks for exit command
			printf(">>>");
			line = line_command;
      for (int i = 0; i < TOKEN_LIST; i++) {
        memset(list[i], 0, sizeof(list[i]));
      }

			getline(&line_command, &size, stdin);//input the  complete line.
			if(strcmp(line_command,"exit\n") == 0){// opttion for exit.
				// exit loop
				exit_loop = 1;
			}
			else if((strcmp(line_command,"\n"))==0){//check for empty lines.
					printf("%s","");
			}
			else{
					int k = 0;// for printing the serial next to "T", for Example, "T0: mkdir lima".
					while ((parte = strtok_r(line, " ", &line))){//extract tokens and put into the array of strings.
						strcpy(list[k],parte);// copy to an array of strings,  I used it this way for reuse the code in future projects.
						k+=1;
					}

					if (strcmp(list[0],comandos)==0 && strcmp(list[1],"\0")==0)
					{
							lfcat();//if right command then lfcat
					}
					else if(strcmp(list[0],"lfcat\0")==0 && strcmp(list[1],"\0")!=0){//check if there is other parameter than shouldnt
							printf("Error: Unsupported parameteres for command: %s\n", list[0]);//bad parameters
					}
					else{
							printf("Error: Unrecognized command: %s\n", list[0]);//wrong command, no lfcat
					}
			}

		}

		//free memory
		//free_double(command_list, LIST_COMMANDS);

		for(int i = 0; i<TOKEN_LIST; i++)
				free(list[i]);
		free(list);
		free(line_command);
		free(parts);

	return 0;
}
/*-----------------------------Program End-----------------------------------*/
