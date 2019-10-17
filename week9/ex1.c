#include <stdio.h>
#include<stdlib.h>

int in(int a, int fr, int* frame){
    int ans=-1;
    for(int i=0; i<fr; i++){
        if(frame[i]==a)
            ans=i;
    }
    return ans;
}
int has_free(int fr, int* frame){
    int ans=-1;
    for(int i=0; i<fr; i++){
        if(frame[i]==-1) {
            ans = i;
            break;
        }
    }
    return ans;
}

int ageing(int fr){
    int hit=0;
    int miss=0;
    int count=1;
    double ratio;

    FILE* fp = fopen("input.txt", "r");
    int* frame = (int*)malloc(fr* sizeof(int));
    int* Rs = (int*) malloc(fr* sizeof(int));
    for(int i=0; i<fr; i++){
        frame[i]=-1;
        Rs[i]=0;
    }

    int a;
    fscanf(fp, "%d", &a);
    while(fgetc(fp)!=EOF){
        fscanf(fp, "%d", &a);
        count++;
    }
    fclose(fp);

    fp = fopen("input.txt", "r");


    for(int i=0; i<count; i++){
        fscanf(fp, "%d", &a);
        int k=-1;
        if(in(a, fr, frame)>=0){
            k = in(a, fr, frame);
            hit++;
        }
        else{
            miss++;
            if(has_free(fr, frame)>=0){
                k = has_free(fr, frame);
                frame[k] = a;
            }
            else{
                int j=0;
                int min=Rs[0];
                for(j=1; j<fr; j++){
                    if (Rs[j]<min) {
                        min = Rs[j];
                        k=j;
                    }
                }
                frame[k] = a;
            }
        }

        for(int j=0; j<fr; j++){
            Rs[j] = Rs[j]>>1;
        }
        if(k>=0)
            Rs[k]+=256;

    }
    fclose(fp);


    ratio = (double)hit/miss;
    printf("Hit/Miss %d/%d ratio with %d page frames is %f\n", hit, miss, fr, ratio);
    return 0;
}

int main(){
    ageing(10);
    ageing(50);
    ageing(100);

    return 0;
}