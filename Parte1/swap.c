#include<stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){

    int a = 10;
    int b = 20;

    printf("direccion de a: %x\n", &a);

    printf("a: %d, b: %d\n", a, b);

    swap(&a, &b);

    printf("a: %d, b: %d\n", a, b);

    return 0;
}