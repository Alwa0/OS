#include <stdio.h>
#include <stdlib.h>


void main() {
    int N;
    scanf("%d", &N);
    int *arr = (int*) malloc(N*sizeof(int));
    for(int i=0; i<N; i++){
        arr[i]=i;
    }
    for(int i=0; i<N; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
}

