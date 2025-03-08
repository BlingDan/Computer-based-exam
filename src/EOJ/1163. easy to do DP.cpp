//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 30;
int w[M];
int f[M][N];
int n, m;

int main()
{
    while(cin >> n)
    {
        memset(f, 0, sizeof f);
        m = 0;

        for(int i = 1; i <= n; i ++) {
            scanf("%d", &w[i]);
            m += w[i];
        }

        for(int i = 1; i <= n; i ++)
            for(int j = 0; j <= m / 2; j ++)
            {
                f[i][j] = f[i - 1][j];
                if(j >= w[i])
                    f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + w[i]);
            }


        // 被abs卡了
        int ans = m - 2 * f[n][m / 2];
        cout << ans << endl;
    }

    return 0;
}
