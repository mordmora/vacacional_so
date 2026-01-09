#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(int argc, char**argv){

    //strchr
    //strstr

    char* path = "/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games";

    char c = '/';

    char* res = strchr(path, c);
    int counter = 0;
    while(res != NULL){
        res++;
        res = strchr(res, c);
        counter++;
    }

    printf("Hay %d /\n", counter);


    return 0;
}