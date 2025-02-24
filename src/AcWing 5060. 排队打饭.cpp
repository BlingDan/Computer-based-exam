//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n;
long long a, t, b;

int main()
{
    cin >> n;

    long long cur = 0;  // 上一位打饭结束时间

    for(int i = 0; i < n; i ++)
    {
        scanf("%lld%lld%lld", &a, &t, &b);

        long long start = max(a, cur); // 当前同学能够开始的最晚时间
        if(start > a + b)
            cout << "-1 ";
        else {
            cout << start << ' ';
            cur = start + t;
        }
    }


    return 0;

}