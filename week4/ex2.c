#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <zconf.h>

int main(void){
    for(int i=0; i<5; i++){
        fork();
        sleep(5);
    }

}
