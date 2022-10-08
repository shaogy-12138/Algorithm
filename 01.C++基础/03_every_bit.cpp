/*
 * @Author : shaogy
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num;
    int ge, shi, bai;
    cin >> num; // 456
    ge = num % 10;
    bai = num / 100;
    shi = (num / 10) % 10;
    cout<<ge<<setw(4)<<shi<<setw(4)<<bai<<endl; // 6   5   4
    return 0;
}
