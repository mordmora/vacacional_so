#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){
    int size = 10;
    int shmid = shmget(IPC_PRIVATE, sizeof(int)*size, IPC_CREAT | 0600);

    int *v = NULL;

    if(fork()){

        v = shmat(shmid, NULL,0);


        wait(NULL);

        for(int i = 0; i < size; i++){
            printf("%d\n", v[i]);
        }

        shmdt(v);
        shmctl(shmid, IPC_RMID, 0);
    }else{

        v = shmat(shmid, NULL,0);

        for(int i = 0; i < size; i++){
            v[i] = i;
        }

        shmdt(v);
    }



    return 0;
}