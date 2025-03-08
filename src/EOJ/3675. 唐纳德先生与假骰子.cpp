//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int a[6];
int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        LL sum = 0;
        LL tmp = -1;
        for(int i = 0; i < 6; i ++) {
            cin >> a[i];
            sum += a[i];
            tmp = max(tmp, 1LL * (i + 1) * a[i]);
        }

        double ans = (double)tmp / sum;
        printf("%.12f\n", ans);
    }

    return 0;
}
