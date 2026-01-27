#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_barrier_t barrier;

void* func(void* args){
    int id = *((int*)args);

    sleep(rand() % 5);
    
    printf("Hilo %d llegó a la barrera\n", id);
    pthread_barrier_wait(&barrier);
    printf("Hilo %d desbloqueado\n", id);

}

int main(){
    pthread_barrier_init(&barrier, NULL, 3);

    pthread_t th[3];
    for(int i = 0; i < 3; i++){
        int* id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&th[i], NULL, func, (void*)id);
    }

    for(int i = 0; i < 3; i++){
        pthread_join(th[i], NULL);
    }

    return 0;

}