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
int cnt[N];
queue<int> q;

int add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa()
{
    // 判断负环可以从任一点开始的负环，所以初始化时候都要压入队列内
    for(int i = 1; i <= n; i ++) {
        st[i] = true;
        q.push(i);
    }

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        // 遍历以t为起始点的边
        for(int i = h[t];  i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])    // 因为存在负环所有一定会减少
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if(cnt[j] >= n)
                    return true;

                if(st[j] == false)
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
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

    if(spfa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
