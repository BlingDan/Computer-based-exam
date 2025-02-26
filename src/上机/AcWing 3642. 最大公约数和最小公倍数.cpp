//
// Created by HUAWEI on 2025/2/19.
//
#include <iostream>
#include <algorithm>

using namespace std;

// 欧几里得算法求最大公约数，最小公倍数是a*b/最大公约数
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x = gcd(n, m);
    cout << x << ' ' << n * m / x << endl;
}
