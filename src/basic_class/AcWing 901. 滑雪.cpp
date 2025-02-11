//
// Created by HUAWEI on 2025/2/7.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;
int h[N][N];
int f[N][N];    // f[i][j]:从坐标（i, j)出发的滑雪最大长度
int n, m;

int dp(int a, int b)
{
    if(f[a][b] != -1) return f[a][b]; // 记忆搜索！！！！

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};;

    f[a][b] = 1;    //别忘记初始化
    for(int i = 0; i < 4; i ++)
    {
        int x = a + dx[i];
        int y = b + dy[i];
        if(x >= 1 && x <= n && y >= 1 && y <= m && h[a][b] > h[x][y])
            f[a][b] = max(f[a][b], dp(x, y) + 1);
    }
    return f[a][b];
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <=n; i ++)
        for(int j = 1; j <= m; j ++)
            scanf("%d", &h[i][j]);

    /**
     *  标记未计算状态： 区分哪些点还没有被计算过。
        实现记忆化： 避免重复计算，提高效率。
        区分有效路径长度： 避免与可能的路径长度 0 混淆。
     */
    memset(f, -1, sizeof f);    // 状态搜索关键所在
    int ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            ans = max(ans, dp(i, j));
    cout << ans << endl;
    return 0;
}
