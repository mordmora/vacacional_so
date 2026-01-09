#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int main(int argc, char** argv){

    int* v = NULL;

    v = (int*)malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++){
        v[i] = i*2;
    }

    for(int i = 0; i < 5; i++){
        printf("%d \n",v[i]);
    }

    free(v);

    return 0;
}