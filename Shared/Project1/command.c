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

#define MAX_PATH 260//maximum number of char allowed for path


struct stat st = {0};

void listDir()
{
    struct dirent *structure;
    DIR *directory = opendir("./");//system call opendir for checking directories "./" is for the current. It returns a pointer.
    if (directory == NULL){//checker
        printf("%s\n", strerror(errno));//
    }
    while ((structure = readdir(directory)) != NULL){//
        printf("%s ", structure->d_name);//printing files in the directory. d_name hint from the project1 description.
    }
    printf("\n");
    closedir(directory);
}

void showCurrentDir()
{
   char *path = char_string(MAX_PATH);//path of the file
   getcwd(path, MAX_PATH);//system call for path
   printf("Path: %s\n", path);
   free(path);
}

void makeDir(char *dirName)
{
    dirName[strlen(dirName)-1]=0;
    //char* pathway = char_string(MAX_PATH);// "/yarayara/yireyire/hola"
    char* folder = char_string(MAX_PATH);// "./hola"
    //pathway = sunir(2, dirName);//sunir is a personalized string concant for paths.
    //folder = sunir(1, dirName);
    //strcpy(pathway,sunir(2, dirName));
    char* temp = sunir(1, dirName);
    strcpy(folder,temp);

    //if (stat(pathway, &st) == -1) {
    if(mkdir(folder, 0700)==0){
    }
    else{
      printf("Unable to access %s: %s\n",dirName, strerror(errno));//not for debugging but part of the program.

    }
    //free(pathway);
    free(folder);
    free(temp);
}

void changeDir(char *dirName)//check aqui
{
  dirName[strlen(dirName)-1]=0;


  int change =chdir(dirName);//change for variable http://man7.org/linux/man-pages/man2/chdir.2.html
    //chdir return 0 if ok or 1 if any error is found. errno
  if (change==0){
    printf("Moved to %s\n", dirName );
  }
  else{
    printf("Cannot moved. %s\n",strerror(errno));
  }

}

void copyFile(char *sourcePath, char *destinationPath)
{
  //sourcePath[strlen(sourcePath)-1] = 0;
  destinationPath[strlen(destinationPath)-1]= 0;

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;
  size_t lenght = 3;

  char* answer = char_string(MAX_PATH);
  char* line = char_string(MAX_PATH);
  while(end_loop == 0){//checks if the file exists or no

      if (stat(sourcePath, &st) == -1){//checking for the file to copy if exists
          printf("File not found.\n");
          break;
      }
      else if(stat(destinationPath, &st) == -1){// needs to check that exists.
          int input = open(sourcePath, O_RDONLY);//source
          if (input < 0){//checker
              printf("Error opening '%s': %s\n",sourcePath, strerror(errno));//report error
              break;
          }

          int output = open(destinationPath, O_CREAT | O_WRONLY, 0644);//destination
          if (output < 0){//checker
            break;
          }

          while(read_code!=0){//if 0, then end of the file.
            read_code = read(input, line, MAX_PATH);
            line[read_code] = '\0';//to signal the end.
            write(output, line, strlen(line));//<--------------system call to write files.
          }
          override = 1;
          close(input);
          close(output);
          if (override == 1){
              break;
          }
      }else{
          printf("%s", "Override?(Y/N): ");//checks if it is overwritten
          getline(&answer,&lenght,stdin);
          if(strcmp(answer, "Y\n") == 0 || strcmp(answer, "y\n") == 0){
              unlink(destinationPath);//delete file first
          }else{
              break;
          }
      }
    }
    free(answer);
    free(line);

}

void moveFile(char *sourcePath, char *destinationPath){

  sourcePath[strlen(sourcePath)]=0;//clean the end and set it to 0 to signal the end.
  destinationPath[strlen(destinationPath)-1]=0;
  //strcpy(sourcePath, "ejemplo.txt");
  //strcpy(destinationPath, "maria.txt");
  printf("%s %s\n",sourcePath, destinationPath );
  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;
  size_t lenght = 3;

  char* answer = char_string(lenght);
  char* line =char_string(MAX_PATH);
  while(end_loop == 0){//checks if the file exists or no
      if(stat(sourcePath, &st) == -1){
          printf("%s\n",  "Source file not found." );//checker to see if the file exists.
          break;
          }
      else if (stat(destinationPath, &st) == -1){
          int input = open(sourcePath, O_RDONLY);//source
          if (input < 0){//checker
              exit(1);
          }

          int output = open(destinationPath, O_CREAT | O_WRONLY, 0644);//destination
          if (output < 0){//checker
            exit(1);
          }

          while(read_code!=0){//if 0, then end of the file.
            read_code = read(input, line, MAX_PATH);
            line[read_code] = '\0';//to signal the end.
            write(output, line, strlen(line));//<--------------system call to write files.
          }
          unlink(sourcePath);//delete file first
          override = 1;
          close(input);
          close(output);
          if (override == 1){
              break;
          }
      }else{
          printf("%s", "Override?(Y/N): ");//checks if it is overwritten
          getline(&answer,&lenght,stdin);
          if(strcmp(answer, "Y\n") == 0 || strcmp(answer, "y\n") == 0){
            unlink(destinationPath);//delete file first
          }else{
              break;
          }
      }
    }
    free(answer);
    free(line);
}

void deleteFile(char *filename){
    //  "/media/sf_CIS415/hola1.txt"-> how to enter for differnent path than current.
    //  hola.txt   -> current directory
    filename[strlen(filename)-1]=0;
    if(unlink(filename) == 0){
    }else{
        printf("Error with '%s': %s\n",filename, strerror(errno));//Show errors of why the file is not deleted. If it doesn't exists it will say it.
    }
}
void displayFile(char *filename)
{
    filename[strlen(filename)-1]=0;
    int read_code = -1;
    char* line = char_string(MAX_PATH);
    if (stat(filename, &st) != -1){
        // needs to check that exists.
          int input = open(filename, O_RDONLY);//source
          if (input < 0){//checker
              printf("Error opening '%s': %s\n",filename, strerror(errno));
              exit(1);
          }
          while(read_code!=0){//if 0, then end of the file.
            read_code = read(input, line, MAX_PATH);
            line[read_code] = '\0';//to signal the end.
            printf("%s\n",line);
          }
          close(input);
    }else{
        printf("%s","File doesn't exists.\n");//print statement that indicates the file is not found. It's not used for debugging but as an alert for the program itself.
    }
    free(line);
    //free(archivo);
}
