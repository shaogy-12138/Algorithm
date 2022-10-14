/*
 * @Author : shaogy
 * @File : 03_dlist_tets
 * @Date : 14/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct  NODE *next, *pre;
}Node;

typedef struct DLIST{
    int len;
    Node *head;
}Dlist;


Node *create_node(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = p->pre = NULL;
    return p;
}

int insert_node(Dlist *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind <0 || ind > l->len) return 0;

    int i;
    Node *p = l->head;
    while(i--){
        p = p->next;
    }

    Node *q = create_node(val);
    q->next = p->next;
    q->pre = p;
    q->next->pre = q;
    p->next = q;
    return 1;
}

int delete_node(Dlist *l, int ind){
    if(l == NULL) return 0;
    if(ind <0 || ind > l->len) return 0;
    int i;
    Node *p = l->head;
    while(i--){
        p = p->next;
    }
    Node *q = p->next;
    if(q->next == NULL){
        p->next = NULL;
    }

    p->next = q->next;
    p->next->pre = q->pre;
    return 1;

}

int main() {

    return 0;
}
