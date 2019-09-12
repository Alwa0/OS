#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <zconf.h>

int main(void){
    int n=0;
    pid_t pid;
    pid = fork();
    if(pid==0){
        int id = getpid();
        printf("Hello from child [%d - %d]\n", id, n);
    }
    if(pid>0){
        int id = getpid();
        printf("Hello from parent [%d - %d]\n", id, n);
    }

}
