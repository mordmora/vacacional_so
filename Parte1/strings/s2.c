#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char**argv){
    //memoria estatica
    char d[20] = "Hola ";
    char s[] = "Mundo";

    strcat(d,s);

    printf("%s\n", d);

    //memoria dinamica: strcat

    char *str = (char*)malloc(10); 

    strcpy(str, "hola");
    printf("%s\n", str);

    char *pq = " mundo";

    char* tmp = (char*)realloc(str, (strlen(str) + strlen(pq) + 1));
    str = tmp;

    strcat(str, pq);

    printf("%s\n", str);

    //strncat

    char dest[15] = "ini: ";
    char* src = "WindowsApps:/mnt/c/Users/USER/AppData/Local/Programs/Microsoft VS Code/bin:/snap/bin";

    int size = sizeof(dest) + strlen(src) - 1;

    strncat(dest, src, size);

    printf("%s\n", dest);

    return 0;
}