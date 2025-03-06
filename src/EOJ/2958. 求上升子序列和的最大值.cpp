//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5010;
int a[N];
int f[N];
int n, T;

int main()
{
    cin >> T;

    for(int count = 0; count < T; count ++)
    {
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);

        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];

        for(int i = 1; i <= n; i ++)    f[i] = a[i];
        for(int i = 2; i <= n; i ++)
            for(int j = 1; j < i; j ++)
            {
                if(a[j] < a[i])
                    f[i] = max(f[i], f[j] + a[i]);
            }

        int ans = -1;
        for(int i = 1; i <= n; i ++)
            ans = max(ans, f[i]);
        printf("case #%d:\n%d\n", count, ans);
    }

    return 0;
}
