//Contar cuantos numeros hay en un archivo de texto

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "faltan argumentos: nombre del archivo\n");
        return 1;
    }

    FILE* f = fopen(argv[1], "r");
    if( f == NULL){
        perror("file");
        return 1;
    }

    char buff[1024];

    fscanf(f, "%[^\n]", buff);

    int table[10] = {0};

    int i = 0;
    int len = strlen(buff);
    while(i < len){
        if(isdigit(buff[i])){
            int dig =  buff[i] - '0';
            table[dig]++;
        }
        i++;
    }

    for(int i = 0; i < 10; i++){
        printf("%d: %d\n", i, table[i]);
    }

    return 0;
}