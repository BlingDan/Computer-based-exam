//
// Created by HUAWEI on 2025/2/9.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int u, v, w;
int n, m;
int p[N];   // 并查集
struct Edge {
    int a, b;
    int w;

    bool operator < (const Edge &other) {
        return w < other.w;
    }
}edge[2 * N];


//并查集
int find(int x)
{
    if(p[x] != x)   p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge[i].a = u;
        edge[i].b = v;
        edge[i].w = w;
    }

    // 边数按照从小到大排序
    sort(edge, edge + m);
    for(int i = 1; i <= n; i ++) p[i] = i;

    int res = 0; //记录权重
    int cnt = 0; //记录最小生成树的边，如果小于n 说明不能构成完整的最小生成树
    for(int i = 0; i < m; i ++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a);
        b = find(b);
        if(a != b)
        {
            res += w;
            cnt ++;
            p[a] = b;
        }
    }

    if(cnt != n - 1)
        cout << "impossible" << endl;
    else
        cout << res << endl;
    return 0;
}
