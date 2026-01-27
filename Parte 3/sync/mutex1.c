#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t tenedores[5] = {PTHREAD_MUTEX_INITIALIZER};

void* filosofos(void* args){

    int id = *((int*)args);
    int izq = id;
    int der = (izq + 1) % 5;

    while(1){

        if(id % 2 == 0){
            printf("El filosofo %d esta pensando...\n", id);
            sleep( rand() % 5 );
            pthread_mutex_lock(&tenedores[izq]);
            pthread_mutex_lock(&tenedores[der]);
            printf("El filosofo %d está comiendo\n", id);
            sleep( rand() % 5 );
            pthread_mutex_unlock(&tenedores[izq]);
            pthread_mutex_unlock(&tenedores[der]);
        }else{
            printf("El filosofo %d esta pensando...\n", id);
            sleep( rand() % 5 );
            pthread_mutex_lock(&tenedores[der]);
            pthread_mutex_lock(&tenedores[izq]);
            printf("El filosofo %d está comiendo\n", id);
            sleep( rand() % 5 );
            pthread_mutex_unlock(&tenedores[der]);
            pthread_mutex_unlock(&tenedores[izq]);

        }


    }


    return NULL;
}



int main(){

    pthread_t th[5];

    for(int i = 0; i < 5; i++){
        int* id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&th[i], NULL, filosofos, (void*)id);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(th[i], NULL);
    }

    for(int i = 0; i < 5; i++){
        pthread_mutex_destroy(&tenedores[i]);
    }

    return 0;
}