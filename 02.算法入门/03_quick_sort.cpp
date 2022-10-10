/*
 * @Author : shaogy
 * @File : 03_quick_sort
 * @Date : 10/10/2022
 * @Description ://TODO
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define OPT 0

typedef int (*Fp)(int *, int, int);   // 函数指针
int partation(int arr[], int left, int right);
int partation_opt(int arr[], int left, int right);
void quick_sort(int arr[], int left, int right, Fp p);
void display(int *arr, int len);
void copy_arr(int goal[], int source[], int len);
void my_swap(int &a, int &b);

int main() {

    int a = 5, b = 4;
    my_swap(a, b);
    cout<<a<<"   "<<b<<endl;
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    Fp p;
    cout<<"排序前： ";
    display(arr1, sizeof(arr1)/sizeof(int));

    sort(arr2, arr2 + sizeof(arr1)/sizeof(int));
    if(0==OPT){
        p = partation;
    }else{
        p = partation_opt;
    }
    quick_sort(arr1, 0, sizeof(arr1)/sizeof(int) - 1, p);
    cout<<"排序后: ";
    display(arr1, sizeof(arr1)/sizeof(int));
    cout<<"排序后: ";
    display(arr2, sizeof(arr2)/sizeof(int));
    return 0;
}
int partation(int arr[], int left, int right){
    int l = left, r = right;
    int tmp = arr[left];

    while(l < r){
        while((l<r) && (arr[r] > tmp)){
            r--;
        }
        if(l < r){
            arr[l] = arr[r];
            l++;
        }
        while((l < r) && (arr[l] < tmp)){
            l++;
        }
        if(l < r){
            arr[r] = arr[l];
            r--;
        }
    }
    arr[l] = tmp;
    return l;
}

int partation_opt(int arr[], int left, int right){
    int l = left, r = right;
    int tmp = arr[left];

    while(l < r){
        while((l<r) && (arr[r] > tmp)){
            r--;
        }

        while((l < r) && (arr[l] <= tmp)){
            l++;
        }

        if(l < r){
            my_swap(arr[l], arr[r]);
            l++, r--;
        }
    }

    if(arr[l] > tmp){
        my_swap(arr[l-1], arr[left]);
        return l-1;
    }
    my_swap(arr[l], arr[left]);
    return l;
}

void quick_sort(int arr[], int left, int right, Fp p){
    if(right > left){
        // int ind = partation(arr, left, right);
        // int ind = partation_opt(arr, left, right);
        int ind = p(arr, left, right);
        cout<<"ind = "<<ind<<endl;
        quick_sort(arr, left, ind-1, p);
        quick_sort(arr, ind+1, right, p);
    }
    return;
}

void display(int *arr, int len){
    int i = 0;
    for(; i < len; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return;
}

void copy_arr(int goal[], int source[], int len){
    int i;
    for(i = 0; i < len; i++){
        goal[i] = source[i];
    }
    return;
}

void my_swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}