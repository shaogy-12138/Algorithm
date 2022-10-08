/*
 * @Author : shaogy
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double d = sqrt(2.0);
    cout<<"1-精度设置： "<<endl;
    int i;
    for(i = 0; i < 5; i++){
        cout << setprecision(i) << d << endl; // 设置不同精度 有效位数  1   1   1.4  1.41  1.414
    }
    cout<<"2-当前精度: "<<cout.precision()<<endl;  // 4
    cout<<"3-当前域宽: "<<cout.width()<<endl;  // 0
    cout<<setw(6)<<d<<endl; // 默认右对齐 // _1.414  (占6位)
    cout<<"4-当前填充字符: "<<endl;
    cout<<setfill('*')<<setw(10)<<d<<endl; // 通过setfill可以直接插入流    *****1.414  (填充字符为'*' 填充字符和d共占10位)
    return 0;
}
