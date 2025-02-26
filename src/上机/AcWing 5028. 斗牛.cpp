//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5;
int a[2 * N];
int n, sum, w;

// u 当前的点， cnt 选中数的个数， res 选中整数的和
void  dfs(int u, int cnt, int res)
{
    if(u == N + 1) {
        if(cnt == 3 && res % 10 == 0)
            w = (sum - res) %  10;
        return;
    }

    dfs(u + 1, cnt + 1, res + a[u]);
    dfs(u + 1, cnt, res);
}

int main()
{
    int m;
    scanf("%d", &m);

    while(m --)
    {
        sum = 0;
        w = -1;
        for(int i = 1; i <= 5; i ++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        dfs(1, 0, 0);
        cout << w << endl;
    }

    return 0;
}
