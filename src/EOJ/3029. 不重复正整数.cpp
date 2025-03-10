//
// Created by HUAWEI on 2025/3/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 60;

int T, n, m;
int ans;
void dfs(int x, int res)
{
    if(res == n) {
        ans ++;
        return;
    }
    if(x > m || res > n)   return;

    for(int i = x + 1; i <= m; i ++)
        dfs(i, res + i);
}
int main()
{
    cin >> T;
    for(int count = 0; count < T; count ++)
    {
        ans = 0;

        cin >> n >> m;
        dfs(0, 0);

        printf("case #%d:\n%d\n", count, ans);
    }
    return 0;
}
