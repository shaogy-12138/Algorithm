/*
 * @Author : shaogy
 * @File : 06_queue_test_bsf
 * @Date : 11/10/2022
 * @Description ://TODO 
**/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define maxn 256
typedef struct POINT{
    int x, y;
    int step;
}Point;

int dx[8] = {-2,-2, -1, -1, 1, 1, 2, 2,};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1,};
bool vis[maxn][maxn];
int sx, sy, ex, ey, tx, ty, L;

void queue_test();
int bsf();
int main() {
    queue_test();
    return 0;
}

void queue_test() {
    int steps, n;
    while(cin>>n) {
        for (int i = 0; i < n; i++) {
            cin >> L;
            cin >> sx >> sy;
            cin >> ex >> ey;

            steps = bsf();
            cout << "(" << sx << "," << sy << ")->(" << ex << ", " << ey << ") need " << steps << " steps." << endl;
        }
    }
    return;
}

int bsf() {
    if (sx == ex && sy == ey) return 0; // 起点和终点相同
    memset(vis, 0, sizeof(vis)); // 棋盘 & 初始化为0
    queue <Point> Q, q_cpy; //

    Point start, node; // 起点 & 任一点

    start.x = sx;  // 初始
    start.y = sy;  // 初始
    start.step = 0; // 0
    Q.push(start); // 将起点入栈
    q_cpy = Q;

    int step, x, y;
    while (!Q.empty()) { //队列不空
        start = Q.front(), Q.pop(); // 取出队首
        x = start.x;
        y = start.y;
        step = start.step;
        for (int i = 0; i < 8; i++) {  //向8个方向走
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx == ex && ty == ey) return step + 1;  // 如果走到终点， 直接返回当前步数 + 1
            if (tx >= 0 && tx < L && ty >= 0 && ty < L && !vis[tx][ty]) { // 如果在棋盘内 && 未走过某一点
                node.x = tx;
                node.y = ty;
                node.step = step + 1;
                Q.push(node); //记录该点
                vis[tx][ty] = true;
            }
        }

        q_cpy = Q;
        cout<<"q_cpy.size = "<<q_cpy.size()<<endl;
        int q_cpy_size = q_cpy.size();
        for(int i = 0; i < q_cpy_size; i++){
            cout<<"("<<q_cpy.front().x<<", "<<q_cpy.front().y<<")["<<q_cpy.front().step<<"]  ";
            q_cpy.pop();
        }
        cout<<endl;
    }
    return step + 1;
}
