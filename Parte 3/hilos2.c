#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

typedef struct args1
{
    int a;
    int b;
    int c;
} args;

void* func1(void* arg){
    args* i = (args*)arg;
    printf("a: %d\n", i->a);
    printf("b: %d\n", i->b);
    printf("c: %d\n", i->c);
    free(i);
}

int main(){

    pthread_t threads[3];

    for(int i = 0; i < 3; i++){
        args* arg = (args*)malloc(sizeof(args));
        arg->a = i;
        arg->b = i+1;
        arg->c = i+2;
        pthread_create(&threads[i], NULL, func1, (void*)arg);
    }

    for(int i = 0; i < 3; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}