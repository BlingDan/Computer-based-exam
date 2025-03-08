//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int n, x;
    cin >> x >> n;

    for(int i = 2; i <= n; i ++)
    {
        LL ans = 1LL * x * i / gcd(x, i);
        ans /= x;
        cout << ans << endl;
    }

    return 0;
}
