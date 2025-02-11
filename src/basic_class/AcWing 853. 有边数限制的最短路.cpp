//
// Created by HUAWEI on 2025/2/8.
//
/**
 * Bellman-Ford 的松弛操作: 每一次外层循环（限定的次数）对所有的边进行松弛操作
 * 为什么要备份dist数组？
 * 每次外层循环的目的是更新最多经过i条边的最短路径，确保每次更新都是基于上一轮的结果
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
struct Edge {
    int a, b;
    int w;
}e[M];  //将每个边保存下来

int n, m, k;
int dist[N];
int back_up[N]; //备份数组防止串联

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // Bellman-Ford 核心逻辑
    for(int i = 0; i < k; i ++) // k次循环
    {
        // 备份 dist 数组
        memcpy(back_up, dist, sizeof dist);

        // 遍历所有边，进行松弛操作
        for(int j = 0; j < m; j ++)
        {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], back_up[a] + w);
        }
    }

    // 判断是否可达
    // if(dist[n] > 0x3f3f3f3f / 2)
    //     return -1; //虽然除以二仍认为是无穷
    // else
    return dist[n];
}


int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++)
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);

    int ans = bellman_ford();
    if(ans > 0x3f3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}
