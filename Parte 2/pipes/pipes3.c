#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>


int main(){

    //int fd[2];
    //int fd1[2];
    //int fd2[2];

    //pipe(fd);
    //pipe(fd1);
    //pipe(fd2);
    int n_hijos = 2;

    int fd[3][2];

    for(int i = 0; i < 3; i++){
        pipe(fd[i]);
    }

    pid_t root = getpid();

    int i = 0;
    for(; i < n_hijos; i++){
        if(!fork()){
            break;
        }
    }

    if(root == getpid()){

        close(fd[0][0]);
        close(fd[2][1]);

        int a = 10;

        write(fd[0][1], &a, sizeof(int));

        read(fd[2][0], &a, sizeof(int));
        printf("Padre leyó %d\n", a);
        close(fd[0][1]);
        close(fd[2][0]);

    }else{

        for(int j = 0; j < n_hijos; ++j){
            if(j == i){
                close(fd[i][1]);
            }else if (j == i+1){
                close(fd[i+1][0]);
            }else{
                close(fd[j][0]);
                close(fd[j][1]);
            }
        }

        int a;
        read(fd[i][0], &a, sizeof(int));
        printf("Hijo %d leyó %d\n", i, a++);
        write(fd[i+1][1], &a, sizeof(int));

        close(fd[i][0]);
        close(fd[i+1][1]);
    }
    return 0;
}