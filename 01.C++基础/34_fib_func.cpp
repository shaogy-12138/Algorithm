/*
 * @Author : shaogy
 * @File : 34_fib_func
 * @Date : 8/10/2022
 * @Description : 斐波那契数列: f(1) = f(2) = 1, f(n) = f(n - 1) + f(n - 2)  n>2
**/

#include <iostream>

using namespace std;

// 1. 使用递归实现斐波那契数列
int fib_func_1(int n){
    if(n == 1  || n == 2) return 1;
    return fib_func_1(n-1) + fib_func_1(n-2);
}

// 2. 不使用递归实现斐波那契数列
int fib_func_2(int n){
    if(n <= 2) return 1;
    int a = 1, b = 1;
    while(n>2){

        b = a + b;
        a = b - a;
        n--;

    }
    return b;
}

int main() {
    int n;
    cin>>n;
    cout<<fib_func_1(n)<<endl;
    cout<<fib_func_2(n)<<endl;
    return 0;
}
