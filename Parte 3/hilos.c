#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int a;

void* rutina(void* args){
    int arg = *(int*)args;
    printf("arg: %d\n", arg);
    return NULL;
}

int main(){

    pthread_t thread;
    int arg = 4;
    pthread_create(&thread, NULL, rutina, (void*)&arg);
    pthread_join(thread, NULL);

    printf("%d\n", a);

    return 0;
}