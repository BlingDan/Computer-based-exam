//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 30, M = 100010;
int f[N][M];
int w[N];
int p[N];
int n, m;

int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        memset(f, 0, sizeof f);
        cin >> n >> m;

        for(int i = 1; i <= n; i ++)
            cin >> w[i] >> p[i];

        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
            {
                f[i][j] = f[i - 1][j];
                if(j >= w[i])
                    f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + p[i]);
            }

        cout << f[n][m] << endl;
    }
    return 0;
}
