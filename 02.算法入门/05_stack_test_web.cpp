/*
 * @Author : shaogy
 * @File : 05_stack_test_web
 * @Date : 11/10/2022
 * @Description :
 * 题目描述（POJ1028）： 标准的Web浏览器包含在最近访问过的页 面中向后和向前移动的功能。实现这些特性的一种方法是使用两个栈来 跟踪前后移动可以到达的页面。
 * 支持以下命令。
 * • BACK：将当前页面推到前向栈的顶部。从后向栈的顶部弹出页 面，使其成为新的当前页面。如果后向栈为空，则忽略该命令。
 * • FORWARD：将当前页面推到后向栈的顶部。从前向栈顶部弹出页 面，使其成为新的当前页面。如果前向栈为空，则忽略该命令。
 * • VISIT：将当前页面推到后向栈的顶部，使URL成为新的当前页 面。前向栈清空。
 * • QUIT：退出浏览器。
 *
 * 假设浏览器的最初页面为URL ***###.acm.org/ （对“http://”用“***”代替，对“www”用“###”代替）。
 * 输入： 输入是一系列BACK、FORWARD、VISIT、QUIT命令。URL没有 空白，最多有70个字符。任何时候，
 * 在每个栈中都不会超过100个元 素。QUIT命令表示输入结束。
 *
 * 输出： 对于除QUIT外的每个命令，如果不忽略该命令，则在执行 该命令后单行输出当前页的URL，
 * 否则输出“Ignored”。QUIT命令没有 输出。
**/

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

void stack_test();
int main() {
    stack_test();
    return 0;
}

void stack_test(){
    stack<string>backward, forward;
    string cur= "https//:www.acm.org/", url, cmd;
    while(cin>>cmd){
        // 假定命令只有QUIT、VISIT、BACK、FORWORK
        if(cmd == "QUIT") break;
        if(cmd == "VISIT"){
            cin>>url;
            backward.push(cur);
            while(!forward.empty()){
                forward.pop();
            }
            cur = url;
            cout<<cur<<endl;
        }else if(cmd == "BACK"){
            if(backward.empty()){
                cout<<"Ignored"<<endl;
            }else{
                forward.push(cur);
                cur = backward.top();
                backward.pop();
                cout<<cur<<endl;
            }
        }else if(cmd == "FORWARD"){
            if(forward.empty()){
                cout<<"Ignored"<<endl;
            }else{
                backward.push(cur);
                cur = forward.top();
                forward.pop();
                cout<<cur<<endl;
            }
        }
    }



}
