//
// Created by HUAWEI on 2025/2/20.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int f[N];
int a[N];
/**
 * f[i] 表示以第 i 棵树结尾的最长非递减序列的长度
 */
int main()
{
    int n;

    while(scanf("%d", &n) != -1)
    {
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; i ++)
            if(n == 1) {
                cout << 0 << endl;
                continue;
            }
        int ans = -1;
        for(int d = 1; d < n; d ++)
        {
            memset(f, 0, sizeof f);
            for(int i = 1; i <= n; i ++)
            {
                f[i] = 1;
                int j = i - d;
                if(j >= 1 && a[j] <= a[i])
                    f[i] = f[j] + 1;

                ans = max(ans, f[i]);
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}
