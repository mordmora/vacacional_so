//lectura por bloque
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){

    FILE* f = fopen("archivo.txt", "r");
    if (f == NULL){
        perror("file");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long curr = ftell(f);

    char *str = (char*)malloc(curr + 1);
    if (str == NULL){
        perror("memory");
        return 1;
    }

    rewind(f); 
    fread(str, sizeof(char), curr, f);
    str[curr+1] = '\0'; 
    printf("%s", str);

    free(str);
    fclose(f);

    return 0;
}