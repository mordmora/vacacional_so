#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv){

    FILE* f = fopen(argv[1], "r");
    if(f == NULL){
        perror("file");
        return 1;
    }

    int lines;
    fscanf(f, "%d", &lines);

    for(int i = 0; i < lines; i++){

        char buff[64];
        int input_tokens;
        int output_tokens;

        fscanf(f, "%[^,],%d,%d", buff, &input_tokens, &output_tokens);

        printf("modelo: %s\ntokens de entrada: %d\n tokens de salida: %d\n", buff, input_tokens, output_tokens);
    }

    fclose(f);
    return 0;

}