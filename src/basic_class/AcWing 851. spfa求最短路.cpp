//
// Created by HUAWEI on 2025/2/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int e[N], h[N], ne[N], w[N], idx;
int n, m;
bool st[N]; // 检查更改的始边是否在queue中不需要重复入列，当然堆，pririty_queue也可以实现
int dist[N];
queue<int> q;

int add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;    // 注意注意注意
    st[1] = true;
    q.push(1);

    // 只要队列不空，一直进行
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        // 遍历以t为起始点的边
        for(int i = h[t];  i != -1; i = ne[i])
        {
            int j = e[i];
//            if(st[j] == false) {    // 节点不在队列中
//                if(dist[j] > dist[t] + w[j]) {  // 松弛操作
//                    dist[j] = dist[t] + w[j];
//                    st[j] = true;
//                    q.push(j);  // 标记并放入队列
//                }
            /**
             * 1. w[j]的意思是节点j存放的权重，w[i]是边的权重，w[j]用不到的
             * 2. st[j] = false确保节点已经在队列中，应该先进性松弛操作再判断
             */
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(st[j] == false) {
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int ans = spfa();
    if(ans > 0x3f3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << ans << endl;

    return 0;
}
