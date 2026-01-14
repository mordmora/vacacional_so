#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){

    int n_hijos = 4;
    pid_t padre = getpid();
    int i = 0;

    long int data = 1613241324;
    int fraction = data/n_hijos;
    for(; i < n_hijos; i++){
        if(!fork()){
            break;
        }
    }

    if(padre == getpid()){
        for(int i = 0; i < n_hijos; i++){
            wait(NULL);
        }

        FILE* f = fopen("resultado.txt", "r");
        if (!f){
            perror("file");
            abort();
        }
        long long int result = 0;
        long int tmp;
        for(int ii = 0; ii < n_hijos; ii++){
            fscanf(f, "%ld", &tmp);
            result+=tmp;
        }

        printf("[PROCESO PADRE] -> resultado: %lld\n", result);

    }else{
        long res = 0;
        for(int ii = 0; ii < fraction; ii++){
            res++;
        }

        FILE* f = fopen("resultado.txt", "a");
        if(!f){
            perror("file");
            abort();
        }

        fprintf(f, "%ld\n", res);

        fclose(f);

    }


    return 0;
}