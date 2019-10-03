#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>

void* realloc1(void* a, int n){
    if(a==NULL)
        return malloc(sizeof(a)*n);
    if(n==0){
        free(a);
        return NULL;
    }
    void *result = (void*)malloc(sizeof(a)*n);
    memcpy(a, result, n);
    free(a);
    return result;
}
int main(){
    int* a = (int*) malloc(sizeof(int)*4);
    for(int u=0; u<4; u++){
        a[u]=u;
    }
    for(int i=0; i<4; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    realloc1(a, 6);

    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
