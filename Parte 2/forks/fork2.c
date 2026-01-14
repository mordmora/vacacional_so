#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void print_tree()
{
    char cmd[20] = {""};
    sprintf(cmd, "pstree -cAlp %d", getpid());
    system(cmd);
}
int main(){

    // !fork() -> verdadero si es proceso hijo
    // fork()  -> verdadero si es proceso padre

    //if(!fork()){ //si es el hijo entonces

    //}else{ //sino, es el padre.

    //}
    //pid_t child;
    //if(!(child = fork())){ //si es el hijo, entonces...

    //}else{//si es el padre.

    //}
    int n_hijos = 4;
    pid_t hijos[n_hijos];

    pid_t padre = getpid();  //1234 -> 1235 1236 1237
    int i = 0;
    for(; i < n_hijos; i++){
        if(!fork() == 0){
            break;
        }
    }

    if(padre == getpid()){
        usleep(5000);
        print_tree();
        wait(NULL);
    }else{
        if(i == 0){ //hijo 0
            printf("soy el hijo 0:p\n");
        }else{
            printf("Soy el hijo %d\n", i);
        }
    }

    return 0;
}