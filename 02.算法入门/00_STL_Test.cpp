/*
 * @Author : shaogy
 * @File : 00_STL_Test
 * @Date : 11/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <time.h>

using namespace std;

#define DisPlay(A) do{ \
for(auto i = A.begin(); i != A.end(); i++){ \
cout<<*i<<'\t';}        \
cout<<endl;            \
}while(0)

#define DisPlayII(A, B) do{ \
for(auto i = 0; i < B; i++){ \
for(auto j = A[i].begin(); j != A[i].end(); j++){\
cout<<*j<<'\t';} \
cout<<"+"<<endl;}                        \
}while(0)


void vector_test();
void stack_test();
void queue_test();
int main() {
//    vector_test();
    srand(time(0));
//    stack_test();
    queue_test();
    return 0;
}

void vector_test(){

    /*
     * 1. 创建
     * 2. 插入
     * 3. 删除/清空
     * 4. 遍历
     * 5. resize
     *
     */
    // 1. 使用Vector创建数组
    vector<int>v = {1, 2, 3, 4, 5, 6, 7, 8,};
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;
    vector<int>v1 = {10, 20, 30, 40, 50};  //创建的数组长度为0
    DisPlay(v1);
    cout<<"v1.size() = "<<v1.size()<<endl;
    vector<int>v2(10);  // 创建指定长度的数组, 不指定初始化值， 默认初始化为0
    DisPlay(v2);
    cout<<"v2.size() = "<<v2.size()<<endl;
    vector<int>v3(10, 6); // 创建指定长度数组 & 指定初始化为6(所有元素)
    DisPlay(v3);
    cout<<"v3.size() = "<<v3.size()<<endl;
    vector<int>v4(v); // 创建一个数组， 其内容复制另一个数组
    DisPlay(v4);
    cout<<"v4.size() = "<<v4.size()<<endl;
    vector<int>v5(v.begin()+2, v.end()-3); // 创建一个数组， 其内容复制另一个数组
    DisPlay(v5);
    cout<<"v5.size() = "<<v5.size()<<endl;
    // 二维数组
    vector<int>v6[5]; // 相当于创建5个vector， v6[i]是一个vector
    vector<vector<int>>v7;
    DisPlayII(v6, 5);

    // 2. 增加：可以尾部添加， 也可以中间插入
    v.push_back(66); // 末尾添加， 时间复杂度O(1)
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    v.insert(v.begin() + 2, 999); // index = 2处添加 注意：在指定位置插入，后边元素均需向后移动，因此时间复杂度为O(n)
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    v.insert(v.begin() + 2, 3, 666); // index = 2处添加 3个666
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    v.insert(v.begin() + 2, 999); // index = 2处添加 注意：在指定位置插入，后边元素均需向后移动，因此时间复杂度为O(n)
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    v.insert(v.begin() + 4, v1.begin(), v1.begin()+3); // 向index = 4处插入v1[0]~v1[3-1]的元素
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    // 3. 删除： 可以删除尾部元素， 也可以删除指定元素
    v.pop_back();
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    v.erase(v.begin()+1);
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    v.erase(v.begin()+3, v.begin()+6);
    cout<<"v: ";
    DisPlay(v);
    cout<<"v.size() = "<<v.size()<<endl;

    // 4.遍历 下标法/迭代器
    // 5.改变大小
    for(int i = 0; i < v.size(); i++){
        if(i){
            cout<<" ";
        }
        cout<<v[i];
    }
    cout<<endl;

    v.resize(v.size() - 5); // 如果新的大小小于原长度， 截断后边的部分
    cout<<"v.size() = "<<v.size()<<endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    v.resize(v.size() + 5); // 扩大则新增部分默认初始化为0
    cout<<"v.size() = "<<v.size()<<endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    v.resize(v.size() + 5, 77); // 扩大&指定初始化值
    cout<<"v.size() = "<<v.size()<<endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    v.clear(); // vector清空, 清空后size为0
    cout<<"v.size() = "<<v.size()<<endl;
    for(vector<int>::iterator i = v.begin(); i != v.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    return;
}
void stack_test(){
    /*
     * 1. 创建栈
     * 2. push
     * 3. pop
     * 4. 判空
     * 5. 栈大小
     */

    stack<int>s;

    for(int i = 0; i < 10; i++){
        s.push(rand()%100);
    }

    while(!s.empty()){
        cout<<"s.size = "<<s.size()<<"   "<<s.top()<<endl;
        s.pop();
    }
    return;
}
void queue_test(){
    queue<int>q;
    cout<<"q.size = "<<q.size()<<endl;

    for(int i = 0; i < 10; i++){
        int opt = rand() % 5;
        int val = rand() % 100;
        if(opt < 3){
            cout<<"push "<<val<<" in queue."<< "queue's size = "<<q.size()<<endl;
            q.push(val);
        }else{
            val = q.front();
            q.pop();
            cout<<"pop a val from q's head, "<<val<<"queue's size = "<<q.size()<<endl;
        }

    }

    while(!q.empty()){
        cout<<q.front()<<'\t';
        q.pop();
    }
    cout<<endl;
    return;
}