/*
 * @Author : shaogy
 * @File : 03_sq_queue_test
 * @Date : 20/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_N  10
typedef int ElemType;

typedef struct SQUEUE{
    ElemType *data;
    int head, tail, len;
}Squeue;

void test();
Squeue *create_queue(int len);
int push(Squeue *q, ElemType val);
void pop(Squeue *q);
int isempty(Squeue *q);
int isfull(Squeue *q);
void clear_queue(Squeue *q);
int get_queue_len(Squeue *q);
int get_head(Squeue *q);
int main() {
    srand(time(0));
    test();
    return 0;
}

void test(){
    int i;
    Squeue *q = create_queue(MAX_N );

    for(i = 0; i < 20; i++){
        int opt = rand() % 5;
        int val = rand() % 100;
        if(opt < 3){
            printf("current head = %d, current has %d data\n", get_head(q), get_queue_len(q));
            printf("insert %d to queue!, result = %d\n", val, push(q, val));
            printf(" current has %d data,\n\n", get_queue_len(q));
        }else{
            !isempty(q) && printf("current head = %d, current has %d data\n", get_head(q), get_queue_len(q));
            pop(q);
            printf("pop a val from queue, current has %d data\n\n", get_queue_len(q));
        }
    }

    return;
}
Squeue *create_queue(int len){
    Squeue  *q = (Squeue *) malloc(sizeof(ElemType));
    q->data = (int *) malloc(sizeof(int) * len);
    memset(q->data, 0, sizeof(int) * len);
    q->head = q->tail = 0;
    q->len = len;
    return q;
}
int push(Squeue *q, ElemType val){
    if(q == NULL) return 0;
    if(isfull(q)) return 0;

    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->len;
//    printf("insert = %d %d %d\n", q->head, q->tail, q->len);
    return 1;
}
void pop(Squeue *q){
    if(q == NULL) return;
    if(isempty(q)) return;

    q->head = (q->head + 1) % q->len;
    return;
}
int isempty(Squeue *q){
    return (q->tail == q->head);
}
int isfull(Squeue *q){
    return ((q->tail + 1)%q->len == q->head);
}
void clear_queue(Squeue *q){
    if(q == NULL)return;
    free(q->data);
    free(q);
    return;
}
int get_queue_len(Squeue *q){
    if(q == NULL) return -1;
//    printf("%s %d %d %d\n", __func__ ,q->head, q->tail, q->len);
    return (q->tail - q->head + q->len) % q->len;
}
int get_head(Squeue *q){
    if(q == NULL) return -1;
    if(isempty(q)) return -1;
    return q->data[q->head];
}
