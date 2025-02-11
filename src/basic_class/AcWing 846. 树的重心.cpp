#include <iostream>
#include <cstring>

using namespace std;
/**
 * 2025年1月16日
 * 很不熟练，先是邻接表表示不清楚，邻接表遍历没搞懂
 * dfs还可以，但是dfs修改后就乱套了，什么res,sum乱七八糟的，
 */

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n;
bool st[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b; // 第idx条边的终点
    ne[idx] = h[a]; // 将新的边头插到顶点a的邻接表头部
    h[a] = idx ++; //更新顶点a的邻接表头指针
}

// dfs返回以当前结点为根的子树大小
int  dfs(int u)
{
    int res = 0; // 返回当前结点连通块点数
    int sum = 1; // 保存以当前结点为根的dfs子树中所有点的数量，n -res用
    st[u] = true;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);

    return sum;
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

//    for(int i = 1; i <= n; i ++)
//    {
//        cout << "head:" << i << "--->";
//        for(int j = h[i]; j != -1; j = ne[j])
//            cout << e[j] << "---";
//        cout << endl;
//    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
