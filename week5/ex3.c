#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define MIN 2

int p = 0;
int sleepc = 0;//ne
int sleepp = 1;//ne

void *eat(void* arg){
    while (1) {
        while (!sleepc) ;
            p--;
        if(p<=MIN) {
            sleepc = 0;
            sleepp = 1;
        }
    }
}

void *cook(void* arg){
    while (1) {
        while(!sleepp) ;
            p++;
        if (p >= MAX) {
            sleepp = 0;
            sleepc = 1;
        }
    }
}

int main(void){
    pthread_t consumer;
    pthread_t producer;
    int err = pthread_create(&producer, NULL, cook, NULL);
    if(err!=0){
        printf("Error");
        return 1;
    }
    err = pthread_create(&consumer, NULL, eat, NULL);
    if(err!=0){
        printf("Error");
        return 1;
    }
    while (1){
        printf("consumer:%d producer:%d count:%d\n", sleepc, sleepp, p);
        sleep(1);
    }

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);
}


