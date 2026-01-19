#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>

int main(){

    int fd[2];
    int fd2[2];

    pipe(fd);
    pipe(fd2);


    pid_t child = fork();
    if(!child){ //Hijo

        close(fd[0]);

        char* buff = (char*)calloc(1024, 1);
        scanf("%s", buff);
        buff = (char*)realloc(buff, strlen(buff)+1);
        write(fd[1], buff, strlen(buff)+1);

        close(fd[1]);

    }else{ //Padre
        close(fd[1]);

        char buff[1024];

        read(fd[0], buff, sizeof(buff));
        printf("PADRE -> %s\n", buff);

        close(fd[0]);

        wait(NULL);
    }



    return 0;
}