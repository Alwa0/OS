#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main() {

    int status;
    int fp[2];
    pipe(fp);

    pid_t id1, id2;

    id1 = fork();
    id2 = fork();

    if (id1 != 0 & id2 != 0){
        write(fp[1], &id2, sizeof(id2));
        waitpid(id2, &status, WUNTRACED);
        printf("Status:%d\n", status);
    }
    else if (id1 == 0){
        sleep(3);
        read(fp[0], &id2, sizeof(id2));
        kill(id2, SIGSTOP);
    }
    else {
        while(1){
            sleep(1);
            printf("Second child is alive\n");
        }
    }
}

