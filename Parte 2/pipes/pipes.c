#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){

    int p[2];
    int p2[2];

    pipe(p);
    pipe(p2);

    pid_t child = fork();

    if(child){ //Padre
        close(p[0]);
        close(p2[1]);

        int a = 10;

        write(p[1], &a, sizeof(int));
        read(p2[0], &a, sizeof(int));
        printf("[%d]a: %d\n",getpid(), a);
        close(p[1]);
        close(p2[0]);
    }else{ //Hijo
        close(p[1]);
        close(p2[0]);

        int a;

        read(p[0], &a, sizeof(int));
        printf("[%d]a: %d\n",getpid(), a);
        a++;
        write(p2[1], &a, sizeof(int));


        close(p[0]);
        close(p2[1]);
    }



    return 0;
}