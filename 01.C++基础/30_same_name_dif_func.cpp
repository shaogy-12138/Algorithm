/*
 * @Author : shaogy
 * @File : 30_same_name_dif_func
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>

using namespace std;

void add_func(int a, int b){
    cout<<"int_"<<__func__<<" & "<<__LINE__<<endl;
    return;
}
void add_func(double a, double b){
    cout<<"double_"<<__func__ <<" & "<<__LINE__<<endl;
    return;
}
void add_func(char a, char b){
    cout<<"char_"<<__func__ <<" & "<<__LINE__<<endl;
    return;
}
int main() {
    add_func(1, 2);
    add_func(1.0, 2.0);
    add_func('a', 'b');
    return 0;
}
