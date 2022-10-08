/*
 * @Author : shaogy
 * @File : 08_narcissistic_number
 * @Date : 8/10/2022
 * @Description :水仙花数(abc, a^3 + b^3 + c^3 = abc)
**/

#include <iostream>
#include <cmath>
using namespace std;

int is_narc_num(int num);
int main() {
    int num;
    cin>>num;
    if(is_narc_num(num)){
        cout<<"1-水仙花数"<<endl;
    }else{
        cout<<"0-水仙花数"<<endl;
    }
    return 0;
}

int is_narc_num(int num){
    int ge, shi, bai;
    //cin >> num;
    ge = num % 10;
    bai = num / 100;
    shi = (num / 10) % 10;

    if((pow(ge, 3) + pow(shi, 3) + pow(bai, 3) == num)) return 1;
    return 0;
}
