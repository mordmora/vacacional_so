#include<stdio.h>

struct myObj {
    

};

void saludo(char* str){
    printf("funcion ejecutandose: %s\n",__func__);
    printf("%s\n", str);
}

int main(){

    void (*f)(char*);

    f = saludo;
    f("hola mundo");

    return 0;
}