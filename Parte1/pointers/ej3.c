// 3: invertir un arreglo dinamico
// v = {1, 2, 3, 4, 5}
// v = {5, 4, 3, 2, 1}
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    int n = 5;

    int* v = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        v[i] = i+1;
    }

    int ii = 0;
    int jj = n-1;
    int delta = n/2;

    for(int i = 0; i < n; i++){
        printf("%d \n", v[i]);
    }
    printf("\n");
    while(ii < delta && jj >= delta){
        int tmp = v[ii];
        v[ii] = v[jj];
        v[jj] = tmp;
        ii++;
        jj--;
    }
    for(int i = 0; i < n; i++){
        printf("%d \n", v[i]);
    }


    return 0;
}