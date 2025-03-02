//
// Created by HUAWEI on 2025/3/2.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200;

int a[N];
int d, k;

int main()
{
    cin >> d >> k;

    k = min(k, 100);

    double ans = 0;
    while(k)
    {
        ans = 1.0 / (1.0 + (k - 1) * d + ans);
        k --;
    }

    printf("%.16f", ans);
    return 0;
}
