//lectura de matriz desde un archivo
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "faltan argumentos: nombre del archivo\n");
        return 1;
    }

    FILE* f = fopen(argv[1], "r");
    if(f == NULL){
        perror("file");
        return 1;
    }

    int filas;
    int columas;

    fscanf(f, "%d %d", &filas, &columas);

    int **m = (int**)malloc(sizeof(int*)*filas);
    for(int i = 0; i < filas; i++){
        m[i] = (int*)malloc(sizeof(int) * columas);
    }

    printf("filas: %d\ncolumnas: %d\n", filas, columas);

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columas; j++){
            fscanf(f, "%d", &m[i][j]);
        }
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columas; j++){
            fprintf(stdout, "%d ", m[i][j]);
        }
        fprintf(stdout, "\n");
    }

    fclose(f);
    for(int i = 0; i < filas; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}