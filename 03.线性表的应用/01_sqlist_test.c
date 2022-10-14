/*
 * @Author : shaogy
 * @File : 01_sqlist_test
 * @Date : 14/10/2022
 * @Description ://TODO 
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAX_N   256
typedef struct STATIC_SQLIST{
    int data[MAX_N]; // 静态顺序表
    int length;
}SSqlist;

typedef struct DYNAMIC_SQLIST{
    int *data;   // 动态顺序表
    int length;
}DSqlist;

void sqlist_test();
int insert_val(SSqlist *l, int ind, int val);
int erase_val(SSqlist *l,  int ind);

int main(){
    srand(time(0));
    sqlist_test();
    return 0;
}

void sqlist_test(){

    SSqlist l;
//    printf("sizeof(l) = %d\n", sizeof(SSqlist));
    memset(l.data, 0, sizeof(int) * MAX_N);
    l.length = 0;

    int i = 0;
    printf("-----------\n");
    for(; i < MAX_N - 5; i++){
        l.data[i] = i;
        l.length ++;
    }


    printf("-----------\n");
    for(i = 0; i < 5; i++){
        int ind = rand() % 15 + 3;
        int val = rand() % 256 + 10;
        //printf("-----------\n");
        int result = insert_val(&l, ind, val);
        printf("insert %d at list %d, l->length = %d, Result = %d\n", val, ind, l.length, result);
        //insert_val(&l, ind, val));
    }

    for(i = 0; i < 8; i++){
        int length = l.length;
        int ind = rand() % 15 - 10;
        int val = rand() % 256 + 10;
        //printf("-----------\n");
        int result = erase_val(&l, ind);
        printf("erase  list %d, l->length = %d, Result = %d\n", ind, l.length, result);
        //insert_val(&l, ind, val));
    }
    return;
}

int insert_val(SSqlist *l, int ind, int val){
    if(ind < 0 || ind > l->length){
        return  0;
    }
    int i;
    for(i = l->length; i > ind; i--){
        l->data[i] = l->data[i-1]; // 将待插入结点位置后的元素全部后移一位
    }
    l->data[ind] = val;
    l->length ++;
    return 1;
}

int erase_val(SSqlist *l,  int ind){
    if(ind < 0 || ind > l->length){
        return  0;
    }
    int i;
    for(i = ind; i < l->length-1; i++){
        l->data[i] = l->data[i+1]; // 将待插入结点位置后的元素全部后移一位
    }
    l->length --;
    return 1;
}