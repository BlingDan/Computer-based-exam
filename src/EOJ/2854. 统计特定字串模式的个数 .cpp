//
// Created by HUAWEI on 2025/3/5.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 32;
LL f[N][N];
int n, m;

int main()
{
    for(int i = 1; i <= N; i ++)
        f[i][i] = 1;

    for(int i = 1; i <= N; i ++)
        for(int j = 1; j < i; j ++)
            f[i][j] = 2 * f[i - 1][j] + (1 << (i - 1 - j)) - f[i - 1 - j][j];

    while(cin >> n >> m)
    {
        if(n == -1 && m == -1)
            break;

        cout << f[n][m] << endl;
    }

    return 0;
}
