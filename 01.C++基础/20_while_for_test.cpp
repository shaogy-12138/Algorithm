/*
 * @Author : shaogy
 * @File : 20_while_for_test
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>

using namespace std;
void test_for(int n);
void test_while(int n);
int main() {
    int num;
    cin >> num;
    test_for(num);
    cout<<"==================="<<endl;
    test_while(num);
    return 0;
}


void test_for(int n){
    int i = 1;
    for(; i <= n; i++){
        if(i % 3 == 0) continue;
        cout<<i<<" ";
        if(i % 5 == 0) cout<<endl;
    }
    return;
}
void test_while(int n){
    int i = 1;
    while(i <= n){
        if(i % 3 == 0) continue; // 在这里会宕住
        cout<<i<<" ";
        if(i % 5 == 0) cout<<endl;
        i++;
    }
}