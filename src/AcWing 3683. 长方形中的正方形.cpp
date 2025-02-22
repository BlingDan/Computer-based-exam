//
// Created by HUAWEI on 2025/2/22.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
LL n, m;

int main()
{
    LL ans = 0;
    cin >> n >> m;

    while (n != 0 && m != 0) {
        if (n > m) {
            ans += n / m;
            n %= m;
        } else {
            ans += m / n;
            m %= n;
        }
        // cout << "n: " << n << ", m: " << m << ", ans: " << ans << endl;
    }

    cout << ans  << endl;
    return 0;
}