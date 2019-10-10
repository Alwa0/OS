#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <zconf.h>
#include <sys/resource.h>

int main(){
    struct rusage u;
    for(int i=0; i<10; i++) {
        int *n = malloc(10 * 1024 * 1024);
        memset(n, 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, &u);
        printf("%d: %ld\n", i+1, u.ru_maxrss);
        sleep(1);
    }
    return 0;
}