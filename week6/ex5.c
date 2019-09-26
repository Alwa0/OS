#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
    pid_t p;
    p = fork();
    if (p < 0)
    {
        printf("fork Failed");
        return 1;
    }
    if(p==0){
        while(1){
            printf("I'm alive\n");
            sleep(1);
        }
    }
    else {
        sleep(10);
        kill(p, 15);
    }
    return 0;
}


