//Recorrer una matriz de 3 formas:
//1: Triangular superior
//2: Diagonal principal
//3: Triangular inferior

/*

i = 3
j = 0
    j
    1 2 5 6 7
    3 3 1 2 6
    7 4 2 1 7
i   1 3 5 8 9
    0 1 1 0 0

*/

//entrada: n -> tamaño de la matriz
//n se pasa como argumento

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    if(argc < 2){
        printf("Faltan argumentos: ./a.out <tamaño de matriz>\n");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);

    int** m = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        m[i] = (int*)malloc(sizeof(int)*n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = i + j;
        }
    }

    printf("Matriz completa: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("Recorrido diagonal\n");
    for(int i = 0; i < n; i++){ //recorrido diagonal
        printf("%d \n", m[i][i]);
    }

    printf("Triangular superior\n");
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("Triangular inferior\n");
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; ++i){
        free(m[i]);
    }
    free(m);

    return EXIT_SUCCESS;
}