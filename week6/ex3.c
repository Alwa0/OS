#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void INThandler(int sig){
    char c;
    signal(sig, SIG_IGN);
    printf("\nDid you hit Ctrl-C?\n"
           "Do you really want to exit? [y/n]\n");
    c = getchar();
    if (c == 'y')
        exit(0);
    else
        signal(SIGINT, INThandler);
    getchar();
}

void main() {

    signal(SIGINT, INThandler);
    while (1){}
}
