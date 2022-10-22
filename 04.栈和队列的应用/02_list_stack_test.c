/*
 * @Author : shaogy
 * @File : 02_list_stack_test
 * @Date : 18/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 20

typedef int ElemType;
typedef struct LISTSTACK{
    ElemType data;
    int len;
    struct LISTSTACK *next;
}Lstack;

void test();
Lstack *create_node(int val);
int push(Lstack *s, int val);
void pop(Lstack *s);
ElemType get_top(Lstack *s);
int isempty(Lstack *s);

int main() {
    srand(time(0));
    test();
    return 0;
}
void test(){
    Lstack s = {0, 0,NULL};
    int i = 0;
    for(; i < MAX_N; i++){
        int opt = rand() % 8;
        int val = rand() % 100;
        if(opt < 3){
            printf("push %d to stack ! Stack Len = %d\n", val, s.len);
            push(&s, val);
        }else{
            s.len && printf("pop %d from stack!Stack Len = %d\n", get_top(&s), s.len);
            pop(&s);
        }
    }
}

Lstack *create_node(int val){
    Lstack *s = (Lstack *) malloc(sizeof(Lstack));
    s->data = val;
    s->next = NULL;
    return s;
}
int push(Lstack *s, int val){
    if(s == NULL) return 0;
    Lstack *p = create_node(val);

    p->next = s->next;
    s->next = p;
    s->len ++;
    return 1;

}
void pop(Lstack *s){
    if(s == NULL) return;
    if(s->len == 0) return;
    Lstack *p = s->next;
    s->next = p->next;
    s->len --;
    return;
}
ElemType get_top(Lstack *s){
    return s->next->data;
}
int isempty(Lstack *s){
    return !s->len;
}