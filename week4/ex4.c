#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <zconf.h>
#include <stdlib.h>
#define MAX 256



int main(void){
    char* s = (char*)malloc(sizeof(char)*MAX);

    int position = 0;
    int c;
    int exit=0;

    while (exit==0) {
        c = getchar();
        if (c == EOF || c == '\n') {
            s[position] = '\0';
            system(s);
	    position = -1;
            s = (char*)malloc(sizeof(char)*MAX);
        } 
        else if(c=='~'){
            exit=1;
        }
        else {
            s[position] = (char) c;
        }
        position++;
    }
}
