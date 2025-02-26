//
// Created by HUAWEI on 2025/2/19.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
int ans;
int l, r;

void dfs(LL x)
{
    if(x > r) return;
    if(x >= l && x >= 10)
        ans ++;
    int d = x % 10;
    if(d != 0) dfs(x * 10 + d - 1);
    if(d != 9) dfs(x * 10 + d + 1);
}
int main()
{
    int m;
    cin >> m;
    while(m --)
    {
        scanf("%d%d", &l, &r);
        ans = 0;
        for(int i = 1; i <= 9; i ++)
            dfs(i);
        cout << ans << endl;
    }
}
