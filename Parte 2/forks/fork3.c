#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){

    long long int res = 0;
    long int limit = 1000000000;
    int i;

    pid_t padre = getpid();
    int n_hijos = 4;

    for(; i < n_hijos; i++){
        if(!fork() == 0){
            break;
        }
    }

    if(padre == getpid()){
        for(int i = 0; i < n_hijos; i++){
            wait(NULL);
        }

    }else{
        int target = limit / n_hijos;
        for(int i = 0; i < target; i++){
            res++;
        }
        printf("res: %lld\n", res);
    }
    return 0;
}