#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    FILE* f = fopen("archivo.txt", "r");
    if(f == NULL){
        printf("El archivo no existe\n");
        return 1;
    }

    char buffer1[1024];

    fscanf(f, "%[^\n]", buffer1);

    printf("%s\n", buffer1);

    return 0;
}