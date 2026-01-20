#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define TARGET 100000

int main()
{

    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600);

    int *res = NULL;

    pid_t root = getpid();
    for (int i = 0; i < 4; i++)
    {
        if (!fork())
            break;
    }

    if (root == getpid())
    {

        res = shmat(shmid, NULL, 0);
        *res = 0;
        for(int i = 0; i < 4; i++){
            wait(NULL);
        }

        printf("Resultado: %d\n", *res);

        shmdt(res);
        shmctl(shmid, IPC_RMID, 0);
    }
    else
    {

        res = shmat(shmid, NULL, 0);
        int ii = 0;
        usleep(100000);
        for(int i = 0; i < TARGET; i++){
            ii++;
        }
        *res += ii;
        shmdt(res);
    }

    return 0;
}