#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char**argv){

    if(argc < 2){
        printf("faltan argumentos: nombre del archivo\n");
        return 1;
    }

    FILE* f = fopen(argv[1], "r");
    if (f == NULL){
        perror("file");
        return 1;
    }

    char buffer[1024];

    while((fgets(buffer, sizeof(buffer), f)) != NULL){
        if(buffer[strlen(buffer)-1] == '\n'){
            buffer[strlen(buffer)-1] = '\0';
        }
        printf("%s\n", buffer);
        FILE* fp = fopen(buffer, "r");
        if(fp == NULL){
            perror("file");
            fclose(f);
            return 1;
        }

        char subBuffer[1024];
        if((fgets(subBuffer, sizeof(subBuffer), fp)) != NULL){
            printf("%s\n", subBuffer);
        }
        fclosee(fp);
    }

    return 0;
}