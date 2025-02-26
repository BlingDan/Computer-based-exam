//
// Created by HUAWEI on 2025/2/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int n;
int ans;

void dfs(int u, int f, int depth)
{
    if(depth == n) {
        ans ++;
        return;
    }

    if(u == 0) {
        dfs(0, u, depth + 1);
        dfs(1, u, depth + 1);
    } else {
        dfs(0, u, depth + 1);
    }
}


int main()
{
    scanf("%d", &n);
    dfs(0, -1, 1);
    dfs(1, -1, 1);
    cout << ans << endl;
    return 0;
}
