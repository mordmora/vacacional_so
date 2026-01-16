#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
void print_tree()
{
    char cmd[20] = {""};
    sprintf(cmd, "pstree -cAlp %d", getpid());
    system(cmd);
}

#define NHIJOS 3

void h(int s){}

int main(){

    signal(SIGUSR1, h);

    pid_t padre = getpid();

    pid_t hijos[NHIJOS];
    int i;
    for(i = 0; i < NHIJOS; i++){
        if(!(hijos[i] = fork())){
            break;
        }
    }

    if(padre == getpid()){//padre
        print_tree();

        usleep(5000);
        kill(hijos[NHIJOS - 1], SIGUSR1);
        printf("Señal enviada a -> %d\n", hijos[NHIJOS - 1]);

        pause();

        for(int i = 0; i < NHIJOS; i++){
            wait(NULL);
        }

    }else{//hijos
        pause();
        usleep(5000);

        if(i == 0){
            kill(padre, SIGUSR1);
            printf("Señal enviada al padre\n");
        }else{
            kill(hijos[i-1], SIGUSR1);
            printf("Señal enviada a -> %d\n", hijos[i-1]);

        }
    }
    return 0;
}