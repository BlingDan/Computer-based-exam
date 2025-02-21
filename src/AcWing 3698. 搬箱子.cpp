//
// Created by HUAWEI on 2025/2/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int f[N], a[N];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    int ans = -1;
    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j ++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }

    for(int i = 1; i <= n; i ++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
