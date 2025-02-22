//
// Created by HUAWEI on 2025/2/22.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n, m;
int ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa, int d)
{
    ans = max(ans, d);

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j != fa)
            dfs(j, u, d + 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for(int i = 0; i < n - 1; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(m, -1, 0);

    cout << ans << endl;
    return 0;
}
