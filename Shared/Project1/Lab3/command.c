#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>// from man7.org

#define FILES_NAMES 50//number of files names it can storage
#define LENGHT_PATH 260//number of characteres allowed for path.
#define NUMBER_CHAR 100//number of charcteres that are going to be written in the file.
void writing(char* line, char* point){
  /*function that allows to write in txt files the content of the files in the directory*/
  int read_code = -1;// number of bytes read, 0 if it is the end or -1 if error.

  int value = open(point, O_RDONLY, 0644);//read only
  if (value < 0) {//checker
      exit(1);
  }

  int escribir = open("log.txt", O_CREAT | O_WRONLY | O_APPEND);//write
  if (escribir < 0) {//checker
    exit(1);
  }

  write(escribir, point, strlen(point));
  write(escribir, "\n", 1);

  while(read_code!=0){//if 0, then end of the file.

    read_code = read(value, line, 60);
    line[read_code] = '\0';//to signal the end.
    write(escribir, line, strlen(line));//<--------------system call to write files.
  }
  write(escribir, "\n", 1);
  for (size_t i = 0; i < 80; i++) {
      write(escribir, "-", 1);//<--------------system call to write files. Adding lines for format.
  }
  write(escribir, "\n", 1);//add decorations to the output.

  close(value);
  close(escribir);
}

void lfcat()
{
  FILE* file = fopen("log.txt", "w+");
  fclose(file);//to reset log.txt and start over

///////////////////////////////////////////////////////////////////////////
  char *line = (char *)calloc(NUMBER_CHAR, sizeof(char));//storage the line
///////////////////////////////////////////////////////////////////////////
  printf("<<In lfcat(): Step-01: Fuction called>>\n");
  char path[LENGHT_PATH];//to get the path
  getcwd(path, sizeof(path));//path
  struct dirent *elements;//will hold the elements of the directory
  DIR *directory;
  printf("<<In lfcat(): Step-02: Listing all files in current dir.\n");
  directory = opendir (path);//open directory. Pointer to directory

  char **listado;// holds the words part of the line, array of string
  listado = (char**)calloc(FILES_NAMES,sizeof(char*));
  for(int i = 0; i < FILES_NAMES; i++) {
    listado[i] = (char*)calloc(LENGHT_PATH,sizeof(char));
  }
  if (listado == NULL)// check if it's ok
  {
    exit(1);
  }

  int l = 0;
  while ((elements = readdir(directory)) != NULL){
      strcpy(listado[l], elements->d_name);
      l+=1;
  }
  for (size_t i = l-1; i>0; i--) {

      if(strcmp(listado[i],"1_poem.txt")== 0 || strcmp(listado[i],"2_lyrics.txt")== 0 || strcmp(listado[i],"3_DE_Code.py")== 0 || strcmp(listado[i],"1_poem.txt")== 0){
        printf ("%s\n", listado[i]);//print the name of file in console
        writing(line, listado[i]);//writting file
      }
  }

  for (int i = 0; i < FILES_NAMES; i++) {
      free(listado[i]);
  }
  free(listado);
  closedir (directory);//close DIR system call
  free(line);//delete line malloc
}
