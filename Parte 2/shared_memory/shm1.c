#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/wait.h>
int main()
{

    int id = shmget(IPC_PRIVATE, sizeof(int), S_IWUSR | S_IRUSR | IPC_CREAT);

    int *n = NULL;

    pid_t child = fork();
    if (child != 0)
    {

        n = shmat(id, NULL, 0);
        *n = 10;
        shmdt(n);

        wait(NULL);

        shmctl(id, IPC_RMID, 0);
    }
    else
    {
        n = shmat(id, NULL, 0);
        printf("n: %d\n", *n);
        shmdt(n);
    }

    return 0;
}