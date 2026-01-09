#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){

    char* path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
    char* search = "bin";

    char* res = path;
    int c = 0;
    while( ( res = strstr(res, search)) ){
        c++;
        res++;
    }

    printf("hay %d bin\n", c);

    return 0;
}