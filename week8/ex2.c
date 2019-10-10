#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <zconf.h>

int main(){
    for(int i=0; i<10; i++) {
        int *n = malloc(10485760);
        memset(n, 0, 10485760);
        sleep(1);
    }
    return 0;
}
