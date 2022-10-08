/*
 * @Author : shaogy
 * @File : 31_func_template
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>

using namespace std;

template<class T>
T add(T a, T b){
    return a + b;
}
int main() {
    cout<<add(1, 3)<<endl;
    cout<<add(1.2, 3.3)<<endl;
    return 0;
}
