/*
 * @Author : shaogy
 * @File : 29_gcd_lcm
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>

using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);
void swap(int &a, int &b);

int main() {
    int a, b;
    cin>>a>>b;
    cout<<"gcd = "<<gcd(a, b)<<endl;
    cout<<"lcm = "<<lcm(a, b)<<endl;
    return 0;
}
int gcd(int a, int b){
    if(a < b) swap(a, b);
    int m = a % b;
    while(m != 0){
        a = b;
        b = m;
        m = a % b;
    }
    return b;
}
int lcm(int a, int b){
    int g = gcd(a, b);
    return (a * b / g);
}
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
