/*
 * @Author : shaogy
 * @File : 01_sequence_stack_test
 * @Date : 17/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N  20
int const maxn = 20;

typedef struct DSSTACK{
    int *data;  // 动态顺序表
    int len, top;
}Dstack;

typedef struct SQSTACK{
    int data[MAX_N];  // 静态顺序表
    int base, top;
}Sstack;

void test();
int push(Sstack *s, int val);
void pop(Sstack *s);
int get_top(Sstack *s);
int isempty(Sstack *s);
int isfull(Sstack *s);


int main() {

    srand(time(0));
    test();
    return 0;
}

void test(){
    Sstack s = {{0,}, 0, 0};
    int i = 0;
    for(; i < maxn; i++){
        int opt = rand() % 5;
        int val = rand() % 100;
        if(opt < 3){
            printf("push %d to stack !\n", val);
            push(&s, val);
        }else{
            printf("pop %d from stack!\n", get_top(&s));
            pop(&s);
        }
    }

}
int push(Sstack *s, int val){
    if(s == NULL) return 0;
    if(isfull(s)) return 0;
    s->data[s->top++] = val;
    return 1;
}
void pop(Sstack *s){
    if(s == NULL) return;
    if(isempty(s)) return;
    s->top --;
    return;
}
int get_top(Sstack *s){
    if(isempty(s)) return -1;
    return s->data[s->top - 1];
}
int isempty(Sstack *s){
    return s->base == s->top;
}
int isfull(Sstack *s){
    return s->top >= maxn;
}
