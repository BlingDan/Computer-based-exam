#include <iostream>

using namespace std;

const int N = 110;
int s[N], v[N][N], w[N][N];
int n, m;
int f[N][N];
/**
 *
 * AcWing 9. 分组背包问题 能优化，不想优化累了
 */
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        for(int j = 0; j < s[i]; j ++)
            cin >> v[i][j] >> w[i][j];
    }

    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            for(int k = 0; k < s[i]; k ++)
            {
                if(j >= v[i][k])
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            }
        }

    cout << f[n][m] << endl;
    return 0;
}