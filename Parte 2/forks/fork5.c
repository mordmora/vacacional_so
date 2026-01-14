#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int tam = 1000;

    int n_hijos = 4;
    pid_t padre = getpid();
    int i = 0;
    int delta = tam / n_hijos;
    for(; i < n_hijos; i++){
        if(!fork()){
            break;
        }
    }

    if(padre == getpid()){

        for(int i = 0; i < n_hijos; i++){
            wait(NULL);
        }

    }else{

        int ini = i * delta;
        int end = ini + delta;

        printf("hijo: %d empieza en %d, hasta %d\n", i, ini, end);
        for(int ii = ini; ii < end; ii++){
            continue;
        }
    }

    return 0;
}