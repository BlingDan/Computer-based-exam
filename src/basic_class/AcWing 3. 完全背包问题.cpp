#include <iostream>

using namespace std;

const int N = 1010;
int n, m;

int v[N], w[N];
//int f[N][N];
int dp[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
//朴素写法
//    for(int i = 1; i <= n; i ++)
//        for(int j = 0; j <= m; j ++)
//        {
//            f[i][j] = f[i - 1][j];
//            if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//        }


    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            dp[j] = dp[j];
            if(j >= v[i]) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
//    cout << f[n][m] << endl;
    cout << dp[m] << endl;
    return 0;
}