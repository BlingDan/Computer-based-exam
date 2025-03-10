/**
 * f[state][j] 在状态state下以j为终点的路径长度
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N], weight[N][N];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> weight[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for(int i = 0; i < (1 << n); i ++)
    {
        for(int j = 0; j < n; j ++) {
            if(i >> j & 1) { //如果第j位是1
                // 看之前的第k位的情况
                for(int k = 0; k < n; k ++) {
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);
                }
            }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;

}
