/*
 * @Author : shaogy
 * @File : 07_is_leap_year
 * @Date : 8/10/2022
 * @Description :���꣺ �������� & �ܱ�4����   ���� �ܱ�400������������
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
        cout<<"1-����"<<endl;
    }else{
        cout<<"0-����"<<endl;
    }
    return 0;
}
