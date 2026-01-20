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

    int id = shmget(IPC_PRIVATE, sizeof(int*)*filas + sizeof(int)*columnas*filas, IPC_CREAT | 0600);

    void* base = shmat(id, NULL, 0);
    int** matriz = (int**)base;
    int* datos = (int*)((char*)base + sizeof(int*)*filas); 

    for(int i = 0; i < filas; i++){
        matriz[i] = &datos[i*columnas];
    }

    if(fork()){

        wait(NULL);

        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        shmdt(base);
        shmctl(id, IPC_RMID, 0);
    }else{

        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                matriz[i][j] = i + j;
            }
        }

        shmdt(base);
    }


    return 0;
}