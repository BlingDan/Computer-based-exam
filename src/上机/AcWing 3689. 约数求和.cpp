//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

long long ans;
//void get_divisor_sum(int x)
//{
////    vector<int> t;
//    for(int i = 1; i <= x / i; i ++)
//    {
//        if(x % i == 0) {
//            ans += i;
//            if(i != x / i)
//               ans += x / i;
//        }
//
//    }
//    sort(t.begin(), t.end());
//    cout << x << ':';
//    for(auto i : t) cout << i << ' ';
//    cout << endl;
//}

int main()
{
    int n;
    cin >> n;
//    for(int i = 1; i <= n; i ++)
//        get_divisor_sum(i);

    for(int i = 1; i <= n; i ++)
        ans += i * (n / i);

    cout << ans << endl;
    return 0;
}
