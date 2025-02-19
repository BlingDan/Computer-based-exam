//
// Created by HUAWEI on 2025/2/19.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010, M = 2 * N;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int ans;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

// u 当前结点， fa 父节点
void dfs(int u, int fa, int val)
{
    ans ++;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j == fa || w[i] < val) continue;
        dfs(j, u, val);
    }
}
bool check(int x)
{
    ans = 0;
    dfs(0, -1, x);
    if(ans <= m) return true;
    else return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n - 1; i ++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c), add(b, a, c);
        }

        int l = 0, r = 0x3f3f3f3f;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}
