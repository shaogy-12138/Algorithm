/*
 * @Author : shaogy
 * @File : 02_merge_sort
 * @Date : 10/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr1[10], arr2[10];
void merge(int *arr, int left, int mid, int end);
void merge_sort(int *arr, int left, int right);
void display(int *arr, int len);

int main() {
    int i = 0;
    for(; i < 10; i++){
        cin>>arr1[i];
    }

    for(i = 0; i < 10; i++){
        arr2[i] = arr1[i];
    }

    cout<<"排序前: ";
    display(arr2, 10);
    sort(arr2, arr2 + 10);
    cout<<"排序后: ";
    display(arr2, 10);

    merge_sort(arr1, 0, 9);
    cout<<"排序后: ";
    display(arr1, 10);

    return 0;
}
void merge(int *arr, int left, int mid, int end){
    int *tmp = new int[end - left + 1];
    int i = left, j = mid + 1, k = 0;
    while((i <= mid) && (j <= end)){
        if(arr[i] < arr[j]){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        tmp[k++] = arr[i++];
    }

    while(j <= end){
        tmp[k++] = arr[j++];
    }

    for(i = left, k = 0; i <= end; i++, k++){
        arr[i] = tmp[k];
    }

    delete []tmp;
    return;
}
void merge_sort(int *arr, int left, int right){
    if(right > left){
        // int mid = (left + right) >> 1; // ok
        int mid = left + (right - left)/2; // ok
        // int mid = left + (right - left)>>1; // left = 3, right = 4 => mid = 2 计算出错

        cout<<"left = "<< left<< ", mid = "<<mid<<", right = "<<right<<endl;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        return;
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