#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char** argv){

    char* str = "hola mundo";
    int i = 0;
    //while(*(str + i) != '\0'){// == while(str[i] != '\0')
       // printf("%c\n", *(str + (i++)));
    //}

    for(char* s = str; *s != '\0'; s++){
        printf("%c\n", *s);
    }

    return 0;
}