#include <stdio.h>
#include <signal.h>


void handler_odin(){
    printf("%s\n", "SIGKILL");
}


void handler_dva(){
    printf("%s\n", "SIGSTOP");
}


void handler_tri(){
    printf("%s\n", "SIGUSR1");
}

void main() {

    signal(SIGKILL, handler_odin);
    signal(SIGSTOP, handler_dva);
    signal(SIGUSR1, handler_tri);

    while (1){

    }
}
