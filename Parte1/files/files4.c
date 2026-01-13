//lectura linea a linea

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    FILE* f = fopen("archivo.txt", "r");
    if(f == NULL){
        perror("file");
        return 1;
    }

    char buffer[1024];
    char* str = NULL;
    while((fgets(buffer, sizeof(buffer), f)) != NULL){
        printf("%s", buffer);
    }

    return 0;
}