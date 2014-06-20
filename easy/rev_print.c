#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



void reverse(char *p,int len) {



    char *token;
    char *list[1000];
    int i=0;
    const char s[2] = "-";

    token = strtok(p, s);


    while( token != NULL )
    {

        list[i]=strdup(token);
        i++;

        token = strtok(NULL, s);

    }
    i--;

    while (i>=0) {

        printf ("%s ",list[i]);

        i--;
    }










}

int main(int argc,char **argv) {

    char line[1000];
    char revLine[1000];
    char *work;
    char *p;
    char*q;
    int test=0;
    FILE* f=fopen(argv[1],"r");



    while (fgets(line,1000,f)) {
        if (test) {
            printf ("\n");
        }
        work=strdup(line);
        int i=0;
        int len=strlen(work);
        while (i<len) {
            if (isspace(work[i])) {
                work[i]='-'; // append a delimiter
            }

            i++;
        }

        reverse(work,len);
        test++;




    }

    return 0;






}
