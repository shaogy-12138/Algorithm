/*
 * @Author : shaogy
 * @File : 25_swap_func
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>

using namespace std;

void swap_1(int a, int b);
void swap_2(int &a, int &b);
void swap_3(int *a, int *b);
void swap_4(int a[], int b[2]);

int main() {
    int a = 5, b = 6;
    cout<<"before swap_1: a = "<<a<<", b = "<<b<<endl;
    swap_1(a, b);
    cout<<"after  swap_1: a = "<<a<<", b = "<<b<<endl;

    a = 5, b = 6;
    cout<<"before swap_2: a = "<<a<<", b = "<<b<<endl;
    swap_2(a, b);
    cout<<"after  swap_2: a = "<<a<<", b = "<<b<<endl;

    a = 5, b = 6;
    cout<<"before swap_3: a = "<<a<<", b = "<<b<<endl;
    swap_3(&a, &b);
    cout<<"after  swap_3: a = "<<a<<", b = "<<b<<endl;

    a = 5, b = 6;
    cout<<"before swap_4: a = "<<a<<", b = "<<b<<endl;
    swap_4(&a, &b);
    cout<<"after  swap_4: a = "<<a<<", b = "<<b<<endl;
    return 0;
}

void swap_1(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
    cout<<"swap_1 ing ..."<<"a = "<<a<<", b = "<<b<<endl;
    return;
}

void swap_2(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
    cout<<"swap_2 ing ..."<<"a = "<<a<<", b = "<<b<<endl;
}

void swap_3(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout<<"swap_3 ing ..."<<"a = "<<*a<<", b = "<<*b<<endl;
}

void swap_4(int a[], int b[2]){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout<<"swap_4 ing ..."<<"a = "<<*a<<", b = "<<*b<<endl;
}
