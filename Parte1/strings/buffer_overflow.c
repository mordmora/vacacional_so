#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void funcion_fantasma(){
    printf("has vulnerado el programa :D\n");
}

void caller(){
    char buffer[16];
    printf("Ingresa tu nombre: ");
    gets(buffer);
    printf("Hola, %s.\n", buffer);
}

int main(int argc, char**argv){

    printf("direccion de la funcion secreta: %p\n", (void*)funcion_fantasma);
    caller();
    printf("el programa termino correctamente\n");

    return 0;
}