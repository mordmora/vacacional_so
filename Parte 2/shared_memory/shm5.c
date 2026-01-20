#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){
    int filas = 3;
    int columnas = 3;
    int shmid = shmget(IPC_PRIVATE, sizeof(int)*filas*columnas, IPC_CREAT | 0600);

    int* mat = (int*)shmat(shmid, NULL, 0);

    if(fork()){

        wait(NULL);

        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                printf("%d ", mat[i*filas + j]);
            }
            printf("\n");
        }

    }else{

        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                mat[i*filas + j] = i+j;
            }
        }


    }


    return 0;
}