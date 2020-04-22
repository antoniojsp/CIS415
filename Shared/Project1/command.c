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
    //if (directory == NULL){//checker To check if the
      //  printf("%s\n", strerror(errno));
  //  }
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
   printf("%s\n", path);
   free(path);
}

void makeDir(char *dirName)
{
    //cd printf("mkdir %s\n", dirName );
    char* folder = char_string(MAX_PATH);//hold the name of the folder to create a path for mkdir()
    char* temp = sunir(1, dirName);
    strcpy(folder,temp);
    //printf("%s\n", folder );
    mkdir(folder, 0700);

    free(folder);
    free(temp);
}

void changeDir(char *dirName)//check aqui
{
  char* temp= char_string(100);
  strcpy(temp,dirName);
  int change = chdir(temp);//change for variable http://man7.org/linux/man-pages/man2/chdir.2.html
    //chdir return 0 if ok or 1 if any error is found. errno
  //if (change!=0){//if sucessful, chdir() returns 0.
    //printf("%s\n",strerror(errno));
  //}
  free(temp);
}
void copyFile(char *sourcePath, char *destinationPath)
{
  char* filename = extract_name(sourcePath);
  if(strcmp(destinationPath, ".\0")==0){
      strcpy(destinationPath, filename);
  }

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;//loop ending signal
  size_t lenght = 3;
  char* answer = char_string(MAX_PATH);
  char* line = char_string(MAX_PATH);
  while(end_loop == 0){//checks if the file exists or no
      if (stat(sourcePath, &st) == -1){//checking for the file to copy if exists
          break;
      }
      else if(stat(destinationPath, &st) == -1){// needs to check that exists.
          int input = open(sourcePath, O_RDONLY);//source
          if (input < 0){//chec
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
          printf("%s", "Overwrite?(Y/N): ");//checks if it is overwritten
          getline(&answer,&lenght,stdin);
          if(strcmp(answer, "Y\n") == 0 || strcmp(answer, "y\n") == 0){
              unlink(destinationPath);//delete file first
              break;
          }else{
              break;
          }
      }
    }
    free(answer);
    free(line);
    free(filename);
}

void moveFile(char *sourcePath, char *destinationPath){

  int read_code = -1;
  int override = 0;//ask if override the file
  int end_loop = 0;
  size_t lenght = 3;

  char* answer = char_string(lenght);
  char* line =char_string(MAX_PATH);
  while(end_loop == 0){//checks if the file exists or no
      if(stat(sourcePath, &st) == -1){
          break;
          }
      else if (stat(destinationPath, &st) == -1){
          int input = open(sourcePath, O_RDONLY);//source
          if (input < 0){//checker
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
          unlink(sourcePath);//delete file first
          override = 1;
          close(input);
          close(output);
          if (override == 1){
              break;
          }
      }else{
          printf("%s", "Overwrite?(Y/N): ");//checks if it is overwritten
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
    unlink(filename);//function call that delete the name from the file systen. http://man7.org/linux/man-pages/man2/unlink.2.html
}

void displayFile(char *filename)
{
    int read_code = -1;
    char* line = char_string(MAX_PATH);
    if (stat(filename, &st) != -1){
        // needs to check that exists.
          int input = open(filename, O_RDONLY);//source, it is already checked to exists from the stat fuction.
          while(read_code!=0){//if 0, then end of the file.
            read_code = read(input, line, MAX_PATH);
            line[read_code] = '\0';//to signal the end.
            printf("%s\n",line);
          }
          close(input);
    }
    free(line);
}
