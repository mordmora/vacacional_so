#include<stdio.h>
#include<stdlib.h>

//vectores

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

    int size = 0;

    fscanf(f, "%d", &size);
    printf("size: %d\n", size);

    int *v = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        fscanf(f, "%d", &v[i]);
    }

    for(int i = 0; i < size; i++){
        fprintf(stdout, "%d ", v[i]);
    }

    free(v);
    fclose(f);

    return 0;
}