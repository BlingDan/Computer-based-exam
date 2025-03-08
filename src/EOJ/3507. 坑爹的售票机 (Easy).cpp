//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;
int f[N];   //购买i张船票需要的最少纸币数量
int n, k, p;
int m[6] = {100, 50, 20,10, 5, 1};

// 贪心，需要的纸币数量,X：金额
int  get_max_ticket(int x)
{
    int res = 0;
    for(int i = 0; i < 6; i ++)
    {
        if(x == 0)  break;
        if(x < m[i]) continue;

        res += x / m[i];
        x %= m[i];
    }

    return res;
}
//int main()
//{
//    cin >> n >> k >> p;
//
//    int ans = 0;
//    cout << (n / k) * get_max_ticket(k * p) << endl;
//    cout << get_max_ticket((n % k) * p) << endl;
////    ans = (n / k) * get_max_ticket(k * p) + get_max_ticket((n % k) * p);
////    cout << ans << endl;
//
//    return 0;
//}

int main()
{
    memset(f, 0x3f, sizeof f);
    cin >> n >> k >> p;

    f[0] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= i && j <= k; j ++)
        {
            f[i] = min(f[i], f[i - j] + get_max_ticket(j * p));
        }

    cout << f[n] << endl;

    return 0;
}
