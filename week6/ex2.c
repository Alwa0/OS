#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int fd[2];
    pipe(fd);
    char s1[]="Some text";
    char s2[100];
    pid_t p;
    if (pipe(fd)==-1)
    {
        printf("Pipe Failed");
        return 1;
    }

    p = fork();
    if (p < 0)
    {
        printf("fork Failed");
        return 1;
    }

    write(fd[1], s1, sizeof(s1));

    if(p==0){
        read(fd[0], s2, sizeof(s1));
        printf("%s\n", s2);
    }

}

