#include<stdio.h> //incluye librerías para entrada y salida
#include<stdbool.h>

int main() {

    float a = 3.131;

    char* str = "hola mundo";

    printf("sizeof(int): %ld\n", sizeof(int));
    printf("sizeof(a): %ld\n", sizeof(a));
    printf("a: %.1f\n", a);

    printf("sizeof(str): %d\n", sizeof(str));
    printf("str: %s\n", str);

    //estructuras de control

    for(int i = 0; i < 5; i++){
        printf("%d\n", i);
    }

    bool c = true;

    while(c){
        printf("while\n");
        if(c == 3){
            break;
        }
        c++;
    }

    return 0;
}