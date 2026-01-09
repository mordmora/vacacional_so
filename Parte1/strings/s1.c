#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int arg , char**argv){

    char* s = (char*)malloc(1024);
    scanf("%s", s);

    int size = strlen(s) + 1;

    s = (char*)realloc(s, size);

    printf("%s\n", s);
    printf("sizeof(s): %d\n", sizeof(s));

    free(s);

    return 0;
}