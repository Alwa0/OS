#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void foo(void) {
    sleep(0);
}

int main(void){
    pthread_t* threads = malloc(4* sizeof(pthread_t));
    for(int i=0; i<4; i++){
        int err = pthread_create(&threads[i], NULL, (void *(*)(void *))foo, NULL);
        if(err!=0){
            printf("Error");
            return 1;
        }
        else{
            printf("Thread %d is created\n", i);
        }
        pthread_join(threads[i], NULL);
    }
}


