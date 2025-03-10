//
// Created by HUAWEI on 2025/3/9.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int n;
int u, v;
long long ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int root, int fa, int res)
{
    if(res >= 4) {
        ans ++;
        return;
    }

    for(int i = h[root]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j != fa)
            dfs(j, root, res + 1);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;

    for(int i = 1; i <= n - 1; i ++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    for(int i = 1; i <= n; i ++)
        dfs(i, -1, 1);

    cout << ans / 2 << endl;

    return 0;
}
