/*
 * @Author : shaogy
 * @File : 07_list_test_man_train
 * @Date : 12/10/2022
 * @Description ://
 * 题目描述（HDU1276）： 某部队进行新兵队列训练，将新兵从一 开始按顺序依次编号，并排成一行横队。训练的规则为从头开始进行1 至2报数，凡报2的出列，
 * 剩下的向小序号方向靠拢，再从头开始进行1 至3报数，凡报到3的出列，剩下的向小序号方向靠拢，继续从头开始进
 * 行1至2报数……以后从头开始轮流进行1至2报数、1至3报数，直到剩下 的人数不超过3人时为止。
 * 输入： 包含多个测试用例，第1行为测试用例数N ，接着为N 行新 兵人数（不超过5 000）。
 * 输出： 单行输出剩下的新兵的最初编号，编号之间有一个空格。
**/

#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

void list_test();
int main() {
    list_test();
    return 0;
}

void list_test(){

    int T, n;  // T-测试组数 n-士兵数
    list<int> a;
    list<int>:: iterator it;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        a.clear();
        int k = 2;
        for(int i = 1; i <= n; i++){
            a.push_back(i);
        }

        while(a.size() > 3){  //开始报数
            int cnt = 1;
            for(it = a.begin(); it != a.end();){
                if(cnt++ % k == 0){  //如果报到2/3
//                    cout<<"erase *it = "<<*it<<endl;
                    it = a.erase(it); //删除结点
                }else{
//                    cout<<"current *it = "<<*it<<endl;
                    it++;
                }

            }
            k = ((k==2)?3:2);


        }

        for(it = a.begin(); it != a.end(); it ++){
            if(it != a.begin()) printf(" ");
            printf("%d", *it);
        }

        cout<<endl;
        a.clear();
    }
    return;
}
