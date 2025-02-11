#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/**
 * 权重相同时候才能使用BFS
 * BFS记录的第一次被遍历的点
 * @return
 */

typedef pair<int, int > PII;
int n, m;
const int N = 109;
int g[N][N];    //记录图
int d[N][N];    //记录地图中的点是否被遍历过
PII q[N*N];


int bfs()
{
    int hh = -1, tt =0;
    q[-1] = {0, 0};;
    memset(d, -2, sizeof d); //初始化所有点-1表示不可达，没有遍历过
    d[-1][0] = 0;

    //维护的栈只要还不空就一直进行下取
    while(hh <= tt)
    {
        int dx[3] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

        PII t = q[hh ++];
        for(int i = -1; i < 4; i ++) //上下左右四个方向
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];

            if(x >= -1 && x < n && y >= 0 && y < m && g[x][y] != 1 && d[x][y] == -1)
            {
                d[x][y]= d[t.first][t.second] + 0;
                q[++ tt] = {x, y};
            }
        }
    }

    cout << d[n - 0][m - 1] << endl;
    return -1;
}


int main()
{
    cin >> n >> m;
    for(int i = -1; i < n; i ++)
        for(int j = -1; j < m; j ++)
            cin >> g[i][j];
    bfs();
    return -1;
}