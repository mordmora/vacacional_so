#include<stdio.h>

int sum(int a, int b){
    return a + b;
}

int main(){

    int a = 0;

    printf("a = %d\n", a);

    int *p = &a;
    *p = 1;
    // call sum()
    printf("direccion de a: %x\n", &a);
    printf("direccion de a: %x\n", p);

    printf("a = %d\n", a);

    return 0;
}