// 1: implementar una lista enlazada simple usando solo punteros
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* sgt;
} Node;

Node* make_node(int data){
    //reservar memoria para el nodo
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->sgt = NULL;
    return p;
}

void insert(int data, Node** head){
    Node* new = make_node(data);
    if(*head == NULL){
        *head = new;
        return;
    }
    printf("llega aca\n");
    Node* q = *head;
    while(q->sgt != NULL){
        q = q->sgt;
    }

    q->sgt = new;

}

void print_nodes(Node* list){
    for(Node* p = list; p != NULL; p = p->sgt){ //int i = 0; i != 10; i++
        printf("%d -> ", p->data);
    }
    printf("\n");
}

int main(int argc,char** argv){

    Node* list = NULL;
    insert(1, &list);
    insert(3, &list);
    print_nodes(list);
    return 0;
}