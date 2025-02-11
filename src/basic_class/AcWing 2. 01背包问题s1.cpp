#include <iostream>

using namespace std;

const int N = 1010, V = 1010;


/**
 * 01 背包问题朴素版本
 */
int v[N], w[N];
int f[N][V];

void dp(int n, int m)
{
    // f[i][j] 前i个物品中体积不超过j的最大的总价值
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            //01背包问题中状态转移对应了两种情况

            //situation 1: 不选择第i件物品
            f[i][j] = f[i - 1][j];
            if(j - v[i] >= 0)
                //situation 2: 选择第i件物品，二者取max
                f[i][j] = max(f[i][j], f[i  - 1][j - v[i]] + w[i]);
        }

    cout << f[n][m] << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i =  1; i <= n; i ++)
    {
        cin >> v[i] >> w[i];
    }

    dp(n, m);

    return 0;


}