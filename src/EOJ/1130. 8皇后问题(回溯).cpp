//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
bool col[N], row[N], dg[2 * N], udg[2 * N];
int ans;
int n;

void dfs(int x, int y, int count)
{
    if(count == n) {
        ans ++;
        return;
    }

    if(y == n) {
        y = 0, x ++;
    }

    if(x == n) {
        return;
    }

    // 放
    if(!row[x] && !col[y] && !dg[y - x + n] && !udg[x + y])
    {
        row[x] = col[y] = dg[y - x + n] = udg[x + y] = true;
        dfs(x, y + 1, count + 1);
        row[x] = col[y] = dg[y - x + n] = udg[x + y] = false;
    }

    // 不放
    dfs(x, y + 1, count);
}
void solution()
{
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    memset(dg, 0, sizeof dg);
    memset(udg, 0, sizeof udg);

    ans = 0;
    dfs(0, 0, 0);
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i ++)
    {
        cin >> n;
        solution();
    }

    return 0;
}
