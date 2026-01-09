#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    int f = 5;
    int c = 5;

    //reserva memoria para las filas de matriz
    int **m = (int**)malloc(sizeof(int*)*f);
    for(int i = 0; i < f; i++){
        //reserva memoria para las columnas de la matriz
        m[i] = (int*)malloc(sizeof(int)*c);
    }
    //printf("m apunta a \n");
    //for(int i = 0; i < f; i++){
    //    printf("%p\n", m[i]);
    //}
    //printf("\n");
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = i + j;
            //printf("%p ", &m[i][j]);
        }
        //printf("\n");
    }

    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    //libera la memoria de la matriz
    for(int i = 0; i < f; i++){
        free(m[i]);
    }
    free(m);

    int a = 0;
    int* p = &a;
    int** q = &p;
    int*** r = &q;
    ***r = 1;

    return 0;
}


