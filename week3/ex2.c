#include <stdio.h>
#include <stdlib.h>

void toSwap(int first, int second, int *a){
    int dummy = a[first];
    a[first] = a[second];
    a[second] = dummy;
}

void bubble_sort(int *a, int n){
    for (int out = n-1; out >= 1; out--){
        for (int in = 0; in < out; in++){
            if(a[in]>a[in + 1]) {
                toSwap(in, in + 1, a);
            }
        }
    }
}

int main() {
    return 0;
}


