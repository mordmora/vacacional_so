#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void h(int s){}

int main(){

    signal(SIGUSR1, h);

    pid_t padre = getpid();
    pid_t child = fork();

    if(child != 0){ //padre

        usleep(500000);
        kill(child, SIGUSR1);
        printf("Señal enviada al hijo.\n");
        pause();

    }else{ //hijo
        pause();
        kill(padre, SIGUSR1);
        printf("Señal enviada al padre\n");
    }

    return 0;
}