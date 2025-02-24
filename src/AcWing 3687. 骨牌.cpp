//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010,  MOD = 999983;
int n;
int f[N];

int main()
{
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i ++)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    cout << f[n] << endl;
    return 0;
}
