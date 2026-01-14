#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void print_tree()
{
    char cmd[20] = {""};
    sprintf(cmd, "pstree -cAlp %d", getpid());
    system(cmd);
}

int main()
{

    printf("[%d]Hola mundo\n", getpid());

    pid_t hijo = fork();

    if (hijo == 0)
    { // proceso hijo
        long int res = 0;
        for (int i = 0; i < 10000000; i++)
        {
            res += i;
        }

        printf("resultado: %ld\n", res);
    }
    else
    { // padre
        print_tree();
        wait(NULL);
        printf("proceso padre\n");
    }

    return 0;
}