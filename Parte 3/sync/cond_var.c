#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int turn = -1;

void* func(void* args){

    int i = *((int*)args);

    pthread_mutex_lock(&mtx);
    while(turn != i){
        pthread_cond_wait(&cond, &mtx);
    }
    printf("Hilo %d desbloqueado\n", i);
    turn++;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main(){

    pthread_t th[3];
    for(int i = 0; i < 3; i++){
        int* id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&th[i], NULL, func, (void*)id);
    }
    turn++;
    pthread_cond_signal(&cond);
    for(int i = 0; i < 3; i++){
        pthread_join(th[i], NULL);
    }

    return 0;
}