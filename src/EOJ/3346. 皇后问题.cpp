//
// Created by HUAWEI on 2025/3/2.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 2 * N;
typedef long long LL;

int row[M], col[M], dg[M], udg[M];
int n;

LL combo(LL x)
{
    if(x == 0 || x == 1)
        return 0;
    return x * (x - 1) / 2;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        row[x] ++;
        col[y] ++;
        dg[x + y] ++;
        udg[x - y + n] ++;
    }

    LL res = 0;
    for(int i = 0; i <= 2 * n; i ++)
        res += combo(row[i]) + combo(col[i]) + combo(dg[i]) + combo(udg[i]);

    cout << res << endl;

    return 0;
}
