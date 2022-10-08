/*
 * @Author : shaogy
 * @File : 04_num_to_one_ten_hum
 * @Date : 8/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num;
    int to_one, to_ten, to_hum;
    cin >> num;
    to_one = num + 1;
    to_ten = num * 10;
    to_hum = num / 10;
    cout<<num<<setw(4)<<to_one<<setw(4)<<to_ten<<setw(4)<<to_hum<<endl;
    return 0;
}
