#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int fd[2];
    pipe(fd);
    char s1[]="Some text";
    char s2[100];
    if (pipe(fd)==-1)
    {
        printf("Pipe Failed");
        return 1;
    }
    write(fd[1], s1, sizeof(s1));
    read(fd[0], s2, sizeof(s1));
    printf("%s\n", s2);
}


