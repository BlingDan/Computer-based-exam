//
// Created by HUAWEI on 2025/2/9.
//
/**
 * prime算法和迪杰斯特拉算法很类似，只有一点要注意，dist数组定义
 * 迪杰斯特拉中为点k到起始点的距离
 * prime中为点k到*集合*的距离
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];    // 顶点的平方和边在一个量级上，说明是稠密图直接用二维数组存储
int dist[N];
bool st[N];     // 判断是否已经在集合中

int prime()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);

    for(int i = 0; i < n; i ++)
    {
        // 每次先找到距离集合最近的点
        int t = -1;
        for(int j = 1; j <= n; j ++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

//        cout << t << "\t" << dist[t] << endl;
        // 判断如果选取的最近的点为无穷且不是第一个选的点，则不连通
        if(i && dist[t] == INF) return INF;

        // 标记加入集合
        st[t] = true;
        if(i)
            res += dist[t];

        // 更新集合外的点到集合的距离
        for(int j = 1; j <= n; j ++)
        {
            if(!st[j] && dist[j] > g[t][j]) {
                dist[j] = g[t][j];
            }
        }
    }

    return res;
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i ++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if(u == v)  //自环
            continue;
        else {      //重边中选择最小的边
            g[u][v] = min(g[u][v], w);
            g[v][u] = g[u][v];
        }
    }


    int ans = prime();
    if(ans == INF)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}
