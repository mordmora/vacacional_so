#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

#define SENDINGTO(X,Y) printf("[%d]Señal enviada a -> %d\n", X, Y)

void print_tree()
{
    char cmd[20] = {""};
    sprintf(cmd, "pstree -cAlp %d", getpid());
    system(cmd);
}

#define NHIJOS 5

void h(int s){}

int main(){

    signal(SIGUSR1, h);

    pid_t padre = getpid();
    pid_t childd;
    pid_t hijos[NHIJOS];
    int i;
    for(i = 0; i < NHIJOS; i++){
        if(!(hijos[i] = fork())){
            if(i == 0 || i == (NHIJOS-1)){
                childd = fork();
            }
            break;
        }
    }

    if(padre == getpid()){//padre
        sleep(2);
        print_tree();

        usleep(5000);
        kill(hijos[NHIJOS - 1], SIGUSR1);
        SENDINGTO(getpid(), hijos[NHIJOS-1]);

        pause();

        for(int i = 0; i < NHIJOS; i++){
            wait(NULL);
        }

    }else{//hijos
        pause();
        if(i == 0 || i == (NHIJOS - 1)){ //primer hijo
            if(childd != 0){//padre
                usleep(500000);
                kill(childd, SIGUSR1);
                SENDINGTO(getpid(), childd);
                pause();
                usleep(50000);
                
                if(i == 0){
                    kill(padre, SIGUSR1);
                    SENDINGTO(getpid(), padre);
                }else{
                    kill(hijos[i-1], SIGUSR1);
                    SENDINGTO(getpid(), hijos[i-1]);
                }

            }else{//hijo;
                //pause();
                usleep(50000);
                kill(getppid(), SIGUSR1);
                SENDINGTO(getpid(), getppid());

            }
        }else{ //resto de hijos
            usleep(50000);
            kill(hijos[i-1], SIGUSR1);
            SENDINGTO(getpid(), hijos[i-1]);
        }

    }
    return 0;
}