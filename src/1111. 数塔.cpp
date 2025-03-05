//
// Created by HUAWEI on 2025/3/3.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int g[N][N];
int f[N][N];

int main()
{
    int C;
    cin >> C;

    while(C --)
    {
        memset(f, 0x3f, sizeof f);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= i; j ++)
                cin >> g[i][j];

        f[1][1] = g[1][1];
        for(int i = 2 ; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
            {
                if(j == 1)
                    f[i][j] = f[i - 1][j] + g[i][j];
                if(j == i)
                    f[i][j] = f[i - 1][j - 1] + g[i][j];
                else
                    f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + g[i][j];
            }

        int ans = INF;
        for(int j = 1; j <= n; j ++)
            ans = min(ans, f[n][j]);
        cout << ans << endl;
    }
}
