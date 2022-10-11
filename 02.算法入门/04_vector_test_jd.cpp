/*
 * @Author : shaogy
 * @File : 04_vector_test_jd
 * @Date : 11/10/2022
 * @Description :
 * 题目描述（HDU3527）： X国的情报委员收到一份可靠的信息，信 息表明Y国将派间谍去窃取X国的机密文件。X国指挥官手中有两份名单列表，
 * 一份是Y国派往X国的间谍名单列表，另一份是X国以前派往Y国的 间谍名单列表。这两份名单列表可能有些重叠。因为间谍可能同时扮演 两个角色，
 * 称之为“双重间谍”。因此，Y国可以把双重间谍送回X国。 很明显，这对X国是有利的，因为双重间谍可以把Y国的机密文件带回， 而不必担心被Y国边境拘留。
 * 所以指挥官决定抓住由Y国派出的间谍，让 普通人和双重间谍进入。那么你能确定指挥官需要抓捕的间谍名单吗？
 *
 * 输入：有几个测试用例。每个测试用例都包含4部分。
 * 第1部分包含3个正整数A 、B 、C ，A 是进入边境的人数，B 是Y国将派出的间谍人数，C是X国以前派到Y国的间谍人数。
 * 第2部分包含A 个字符串，为进入边境的人员名单。
 * 第3部分包含B 个字符串，为由Y国派出的间谍名单。
 * 第4部分包含C 个字符串，即双重间谍的名单。
 * 每个测试用例后都 有一个空白行。在一份名单列表中不会有任何名字重复，如果有重复的名字出现在两份名单列表中，则表示同一个人。
 *
 * 输出： 输出指挥官抓捕的间谍名单（按列表B的出现顺序）。如果不应捕获任何人，则输出“No enemy spy”。
 *
 * 示例：
 * 8 4 6
 * zhao qian sun li zhou wu zheng wang   // 所有入境ren
 * zhao qian sun li // y国间谍
 * zhao wu   zheng  // x过间谍
 * >> qian sun li   // 输出y国间谍中非双面间谍
**/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define DisPlay(A) do{ \
for(auto i = A.begin(); i != A.end(); i++){ \
cout<<*i<<'\t';}        \
cout<<endl;            \
}while(0)


void test();
int main() {
    test();
    return 0;
}

void test(){
    vector<string>all, y_to_x, x_to_y, ans;
    int A, B, C;
    string s;
    while(cin>>A>>B>>C){
        cout<<A<<" "<<B<<" "<<C<<endl;
        for(int i = 0; i < A; i++){
            cin>>s;
            all.push_back(s);
        }
        for(int i = 0; i < B; i++){
            cin>>s;
            y_to_x.push_back(s);
        }
        for(int i = 0; i < C; i++){
            cin>>s;
            x_to_y.push_back(s);
        }

        // 在入境人员但是又不在x_to_y中的即为逮捕目标
        for(int i = 0; i < B; i++){
            if(find(all.begin(), all.end(), y_to_x[i]) != all.end()){ // 是进入边境的人
                if(find(x_to_y.begin(), x_to_y.end(), y_to_x[i]) == x_to_y.end()){ // 不是双面间谍
                    ans.push_back(y_to_x[i]);
                }
            }
        }

        if(!ans.size()){ // 没有找到非双重间谍
            cout<<"No enemy spy\n";
        }else{
            DisPlay(ans);
            ans.clear();
        }
        all.clear();
        x_to_y.clear();
        y_to_x.clear();

    }

    return;
}