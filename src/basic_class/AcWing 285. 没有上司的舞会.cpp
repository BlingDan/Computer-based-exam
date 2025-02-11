/**
 * f[root][0/1] 以root为根节点的树是否选择根节点
 * 状态转移方程：
 * 1. 选择root,root的子节点不能选
 * 2.不选择root,子节点随意，取最大值
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;
int e[N], ne[N], h[N], idx;
int happiness[N];
int f[N][2];
bool has_parents[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    f[u][0] = 0; // 没有搞懂，别人解释是要考虑根节点没有子树的情况，我觉得初始化的时候已经为0了这一步就可以省略
    // f[u][0]可以不用写，写了逻辑更清楚而已
    f[u][1] = happiness[u];

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> happiness[i];


    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++) {
        int l, k;
        cin >> l >> k;
        add(k, l);
        has_parents[l] = true;
    }

    int root = 1;
    while(has_parents[root])
        root ++;

    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
