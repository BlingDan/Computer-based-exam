//
// Created by HUAWEI on 2025/2/11.
//
#include <iostream>
#include <algorithm>

using namespace std;

double n, d, k, v;

int main()
{
    cin >> d >> n;
    double ans = 1e9 + 1.0;

    for(int i = 0; i < n; i ++)
    {
        cin >> k >> v;
        ans = min(ans, v * (k / (d - k) + 1));
//        cout << "round" << i << ":" << ans << endl;
    }

    printf("%.6f", ans);
    return 0;
}
