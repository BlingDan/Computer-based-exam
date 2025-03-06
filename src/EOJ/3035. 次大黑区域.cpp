//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 110;
int g[N][N];
bool st[N][N];
set<int, greater<int>> area;
int n, m;
int t;  // 每个黑区域的大小

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int a, int b)
{
    if(st[a][b] || g[a][b] == 0) return;

    t ++;
    st[a][b] = true;
    for(int i = 0; i < 4; i ++)
    {
        int x = a + dx[i], y = b + dy[i];
        if(x >= 1 && x << n && y >= 1 && y <= m && !st[x][y] && g[a][b] == 1)
            dfs(x, y);
    }

    return;
}

int main()
{
    int T;
    cin >> T;

    for(int cnt = 0; cnt < T; cnt ++)
    {
        memset(g, 0, sizeof g);
        memset(st, 0, sizeof st);
        area.clear();

        cin >> n >> m;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                cin >> g[i][j];

        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
            {
                t = 0;
                dfs(i, j);
                area.insert(t);
            }

        int ans;
        int tmp = 0;
        for(auto it:area) {
            tmp ++;
            if(tmp == 2) {
                ans = it;
                break;
            }
        }

        printf("case #%d:\n%d\n", cnt, ans);
    }

    return 0;
}
