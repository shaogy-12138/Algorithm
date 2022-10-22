/*
 * @Author : shaogy
 * @File : 04_list_queue_test
 * @Date : 22/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct QNODE{
    int val;
    struct QNODE *next;
}Qnode;

typedef struct LQUEUE{
    Qnode *front, *rear;
}Lqueue;

Qnode *create_node(int val){
    Qnode *q = (Qnode *) malloc(sizeof(Qnode));
    q->val = val;
    q->next = NULL;
    return q;
}

Lqueue *init_queue(){

    Lqueue *q = (Lqueue *) malloc(sizeof(Lqueue));
    q->front = q->rear = create_node(0);
    //q->front->next = NULL;
    return q;
}



int push_node(Lqueue *q, int val){
    if(q == NULL) return 0;
    Qnode *n = create_node(val);
    q->rear->next = n;
    q->rear = n;
    return 1;
}

int pop_node(Lqueue *q){
    if(q == NULL) return 0;
    if(q->front == q->rear) return 0; // 队空
    Qnode *p = q->front->next;
    q->front->next = p->next;

    if(p == q->rear){
        q->rear = q->front;
    }

    free(p);
    return 1;

}

int get_head(Lqueue *q){
    if(q == NULL) return 0;
    if(q->front != q->rear) return q->front->next->val;
    return -1;
}

void free_queue(Lqueue *q){
    if(q == NULL) return;
    while(q->front !=  q->rear){
        pop_node(q);
    }

    free(q->front);

//    q->front = NULL;
//    q->rear = NULL;
    //
    free(q);
    return;
}
int main() {
    srand(time(0));

    Lqueue *q = init_queue();
    printf("1===========\n");

    printf("2===========\n");
    int max = 20;
    int i;
    for(i = 0; i < max; i++){
        int opt = rand() % 5;
        int val = rand() % 100;
        if(opt < 3){
            printf("push %d to queue! result = %d\n ", val, push_node(q, val));
        }else{
            printf("pop a val from queue!\n");
            pop_node(q);
        }
    }

    Qnode *tmp = q->front->next;
    while (tmp != NULL){
        if(tmp == NULL) break;
        printf("%d ", tmp->val);
        tmp = tmp->next;
        //getchar();
    }
    printf("\n");
    //printf("123ZZ");
    free_queue(q);
    return 0;
}
