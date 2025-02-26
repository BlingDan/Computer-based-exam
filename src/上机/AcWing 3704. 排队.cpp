//
// Created by HUAWEI on 2025/2/20.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 510, M = 5010;
int h[N], e[M], ne[M], idx;
int d[N];   // 顶点入度
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void toposort()
{
    priority_queue<int ,vector<int>, greater<int>> heap;
    for(int i = 1; i <= n; i ++)
        if(d[i] == 0)
            heap.push(i);

    while(heap.size())
    {
        int t = heap.top();
        cout << t << ' ';
        heap.pop();

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(-- d[j] == 0)
                heap.push(j);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b] ++;
    }

    toposort();
    return 0;
}

