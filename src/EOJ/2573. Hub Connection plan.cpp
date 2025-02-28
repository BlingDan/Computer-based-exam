//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prime()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);

    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        if(i && dist[t] == INF) return INF;

        st[t] = true;
        if(i)
            res += dist[t];

        for(int j = 1; j <= n; j ++)
        {
            if(!st[j] && dist[j] > g[t][j])
                dist[j] = g[t][j];
        }
    }

    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c, g[b][a] = c;
    }

    cout << prime() << endl;

    return 0;
}
