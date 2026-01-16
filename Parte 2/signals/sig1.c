#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void h(int s){ //handler
    printf("SEÑAL :p\n");
}

int main(){

    signal(SIGTERM, h);

    for(;;){
        printf("[%d] haciendo algo...\n", getpid());
        sleep(1);
    }


    return 0;
}