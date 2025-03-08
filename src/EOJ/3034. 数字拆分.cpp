//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, MOD = 1e9;

long long f[N];
int n, T;

int main()
{
    cin >> T;
    for(int q = 0; q < T; q ++)
    {
        cin >> n;

        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; i ++)
        {
            // 奇数
            if(i % 2)
                f[i] = f[i - 1];
            else {
                f[i] = (f[i / 2] + f[i - 1]) % MOD;
            }
        }
        printf("case #%d:\n%lld\n", q, f[n]);
    }
    return 0;
}
