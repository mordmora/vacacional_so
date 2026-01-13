//lectura caracter a caracter usando buffer estatico

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    FILE* f = fopen("archivo.txt", "r");
    if(f == NULL){
        printf("El archivo no existe\n");
        return 1;
    }
    char buffer[1024];
    char c;
    int i = 0;
    while((c = fgetc(f))!= EOF){
        printf("saving %c\n", c);
        buffer[i++] = c;
        //c = fgetc(f);
    }
    buffer[i] = '\0';
    printf("%s\n", buffer);

    fclose(f);
    return 0;
}