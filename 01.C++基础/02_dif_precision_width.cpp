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
    cout<<"1-�������ã� "<<endl;
    int i;
    for(i = 0; i < 5; i++){
        cout << setprecision(i) << d << endl; // ���ò�ͬ���� ��Чλ��  1   1   1.4  1.41  1.414
    }
    cout<<"2-��ǰ����: "<<cout.precision()<<endl;  // 4
    cout<<"3-��ǰ���: "<<cout.width()<<endl;  // 0
    cout<<setw(6)<<d<<endl; // Ĭ���Ҷ��� // _1.414  (ռ6λ)
    cout<<"4-��ǰ����ַ�: "<<endl;
    cout<<setfill('*')<<setw(10)<<d<<endl; // ͨ��setfill����ֱ�Ӳ�����    *****1.414  (����ַ�Ϊ'*' ����ַ���d��ռ10λ)
    return 0;
}
