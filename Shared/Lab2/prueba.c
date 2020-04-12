/* this has declarations for fopen(), printf(), etc. */
#include <stdio.h>

/* Arbitrary, just to set the size of the buffer (see below).
   Can be bigger or smaller */
#define BUFSIZE 1000

int main(int argc, char *argv[])
{
    /* the first command-line parameter is in argv[1]
       (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

    char buff[BUFSIZE]; /* a buffer to hold what you read in */

    /* read in one line, up to BUFSIZE-1 in length */
    while(fgets(buff, BUFSIZE - 1, fp) != NULL)
    {
        /* buff has one line of the file, do with it what you will... */

        printf ("%s\n", buff); /* ...such as show it on the screen */
    }
    fclose(fp);  /* close the file */
}
