#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int e[N], ne[N], h[N], idx;
int q[N];   // 队列
int d[N];   // 每个顶点的入度
int n ,m;

void add(int a, int b)  // 别忘记初始化h
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topoLogicalSort()
{
    int hh = 0, tt = -1;    // 用队列维护，记录入度为0的点

    // 开始找到入度为0点入队列
    for(int i = 1; i <= n; i ++) {
        if(d[i] == 0) {
            q[++ tt] = i;
        }
    }

    while(hh <= tt)
    {
        int t = q[hh ++];   //队头出队
        for(int i = h[t]; i != -1; i = ne[i])
        {

            d[e[i]] --; // 当前点的入度减一
            if(d[e[i]] == 0)
                q[++ tt] = e[i];
        }
    }

    if(tt == n - 1) {
        // 队列中点的个数等于图中点的个数，则说明全部点都访问了一遍，可进行拓扑排序
        for(int i = 0; i < n; i ++)
            cout << q[i] << ' ';
    } else
        cout << -1 << endl;

    return;
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;
    int x, y;
    while(m --) {
        scanf("%d%d", &x, &y);
        add(x, y);
        d[y] ++;
    }

    topoLogicalSort();
    return 0;

}
