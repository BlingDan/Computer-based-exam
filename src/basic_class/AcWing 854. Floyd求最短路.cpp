//
// Created by HUAWEI on 2025/2/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int dist[N][N];
int n, Q, m;

void flody()
{
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    cin >> n >> m >> Q;

    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= n; j ++) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }

    for(int i = 0; i < m; i ++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        dist[a][b] = min(dist[a][b], w);
    }

    flody();

    while(Q --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(dist[x][y] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << dist[x][y] << endl;
    }

    return 0;
}
