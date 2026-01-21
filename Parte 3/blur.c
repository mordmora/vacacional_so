#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int** img;
int** ires;
int filas;
int columnas;

typedef struct bounds {

    int ini;
    int fin;

}bounds;

int** read_file(const char* fname){

    FILE* f = fopen(fname, "r");
    if(!f){
        perror("file");
        abort();
    }

    fscanf(f, "%d", &filas);
    fscanf(f, "%d", &columnas);

    int** m = (int**)malloc(sizeof(int*)*filas);
    for(int i = 0; i < filas; i++){
        m[i] = (int*)malloc(sizeof(int)*columnas);
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            fscanf(f, "%d", &m[i][j]);
        }
    }

    fclose(f);

    return m;
}

int window(int i, int j, int inc){

    int inf_limit_x = j - inc;
    int sup_limit_x = j + inc;
    int inf_limit_y = i - inc;
    int sup_limit_y = i + inc;
    long res = 0;
    int count = 0;
    for(int y = inf_limit_y; y <= sup_limit_y; y++){
        for(int x = inf_limit_x; x <= sup_limit_x; x++){
            if(x >= 0 && y >= 0 && y < filas && x < columnas){
                res += img[y][x];
                count++;
            }
        }
    }
    if(count == 0) return 0;
    return (int)(res/count);
}

void* blur(void *args){

    bounds* b = (bounds*)args;

    for(int i = b->ini; i < b->fin; i++){
        for(int j = 0; j < columnas; j++){
            ires[i][j] = window(i, j, 15); //1 para tamaño de ventana de 3x3
        }
    }
    free(b);
}

void print_to_file(const char* fname){
    FILE* f = fopen(fname, "w");
    if(!f){
        perror("file");
        abort();
    }
    
    fprintf(f, "%d\n", filas);
    fprintf(f, "%d\n", columnas);
    
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            fprintf(f, "%d ", ires[i][j]);
        }
        fprintf(f, "\n");
    }
    
    fclose(f);
}

int main(int argc, char** argv){

    if(argc < 3){
        printf("Faltan argumentos: uso -> ./a.out nhilos nombre_archivo\n");
        return 1;
    }

    int n_hilos = atoi(argv[1]);
    img = read_file(argv[2]);

    ires = (int**)malloc(sizeof(int*)*filas);
    for(int i = 0; i < filas; i++){
        ires[i] = (int*)malloc(sizeof(int)*columnas);
    }

    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t)*n_hilos);

    int delta = filas / n_hilos;

    for(int i = 0; i < n_hilos; i++){
        bounds* b = (bounds*)malloc(sizeof(bounds));
        b->ini = i*delta;
        b->fin = (i == n_hilos-1) ? filas : b->ini + delta;
        printf("lanzando hijo con limite desde %d hasta %d\n", b->ini, b->fin);
        pthread_create(&threads[i], NULL, blur, (void*)b);
    }
    for(int i = 0; i < n_hilos; i++){
        pthread_join(threads[i], NULL);
    }

    print_to_file("output.txt");

    for(int i = 0; i < filas; i++){
        free(img[i]);
        free(ires[i]);
    }

    free(img);
    free(ires);

    return 0;
}