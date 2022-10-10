/*
 * @Author : shaogy
 * @File : 01_max_value
 * @Date : 9/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector<int>w {4, 10, 7, 11, 3, 5, 14, 2};
    for( auto i = w.begin(); i != w.end(); i++){
        cout<<*i<<' ';
    }
    cout<<endl;
    sort(w.begin(), w.end());
    for( auto i = w.begin(); i != w.end(); i++){
        cout<<*i<<' ';
    }
    cout<<endl;

    int c_max = 30, sum = 0;
    int i;
    for(i = 0; i < w.size(); i++){
        sum += w[i];
        if(sum > c_max){
            break;
        }else if(sum == c_max){
            i++;
            break;
        }
    }

    cout<<"可以装载 "<<i<<" 件古董"<<endl;
    return 0;
}
