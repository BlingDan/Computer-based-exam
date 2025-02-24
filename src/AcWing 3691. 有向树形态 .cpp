//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 25;
long long dp[N];    //n个结点能够构造二叉树个数

int main()
{
    int n;
    cin >> n;

    dp[0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < i; j ++)
            dp[i] += dp[j] * dp[i - j - 1];

    cout << dp[n] << endl;

    return 0;
}
