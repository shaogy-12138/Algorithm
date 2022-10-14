/*
 * @Author : shaogy
 * @File : 02_list_insert_delete
 * @Date : 14/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct  NODE{
    int data;
    struct NODE *next;
}Node;

typedef struct LIST1{
    int len;
    Node *head;
}List1;

typedef struct LIST2{
    int len;
    Node head;
}List2;


Node *create_node(int val){
    Node *p = (Node *) malloc(sizeof(Node));
    p->next = NULL;
    p->data = val;
    return p;
}

int insert_node_1(List1 *l, int ind, val){
    if(l == NULL) return 0;
    if(ind < 0 || l > l->len) return 0;
    Node *p = l->head, *q = create_node(val);
    int i = ind;
    while(i--){
        p = p->next;
    }

    q->next = p->next;
    p->next = q;

    l->len ++;
    return  1;
}

int insert_node_2(List2 *l, int ind, val){
    if(l == NULL) return 0;
    if(ind < 0 || l > l->len) return 0;
    Node *p = &(l->head), *q = create_node(val);
    int i = ind;
    while(i--){
        p = p->next;
    }

    q->next = p->next;
    p->next = q;

    l->len ++;
    return  1;
}
int delete_node(List1 *l, int ind){
    if(l == NULL) return 0;
    if(ind < 0 || l >= l->len) return 0;
    Node *p = &(l->head);
    int i = ind;
    while(i--){
        p = p->next;
    }

    Node *q = p->next;

    p->next = q->next;
    l->len --;
    return 1;
}

int main() {

    return 0;
}
