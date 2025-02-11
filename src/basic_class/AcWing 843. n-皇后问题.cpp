#include <iostream>

using namespace std;

const int N = 10;
int n;
char g[N][N];
bool row[N], col[N], dg[2 * N], udg[2 * N];

void dfs(int x, int y, int count)
{
    if(count == n)
    {
        for(int i = 0; i < n; i ++)
            cout << g[i] << endl;
        cout << endl;
        return;
    }

    if(y == n)
    {
        y = 0, x ++;
    }

    if (x == n)
    {
        return; // 边界检查：x 超出范围
    }

    // 放皇后
    if(!row[x] && !col[y] && !dg[y - x + n] && !udg[x + y])
    {
        row[x] = col[y] = dg[y - x + n] = udg[x + y] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, count + 1);
        row[x] = col[y] = dg[y - x + n] = udg[x + y] = false;
        g[x][y] = '.';
    }

    // 不放皇后
    dfs(x, y + 1, count);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';

    dfs(0, 0, 0);
    return 0;
}