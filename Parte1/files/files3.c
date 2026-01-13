//Lectura caracter a caracter usando memoria dinamica

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    FILE* f = fopen("archivo.txt", "r");
    if(f == NULL){
        perror("file");
        return 1;
    }

    char *str = NULL;
    char c;
    int len = 0;
    while((c = fgetc(f)) != EOF){
        len++;
        str = (char*)realloc(str, len + 1);
        str[len-1] = c;
    }

    printf("%s\n", str);

    free(str);
    fclose(f);

    return 0;
}