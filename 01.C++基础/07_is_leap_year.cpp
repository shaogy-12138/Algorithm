/*
 * @Author : shaogy
 * @File : 07_is_leap_year
 * @Date : 8/10/2022
 * @Description :闰年： 非整百年 & 能被4整除   或者 能被400整除的整百年
**/

#include <iostream>

using namespace std;
int is_leap_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 1;
    return 0;
}
int main() {
    int year;
    cin>>year;
    if(is_leap_year(year)){
        cout<<"1-闰年"<<endl;
    }else{
        cout<<"0-闰年"<<endl;
    }
    return 0;
}
