#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
char a[N], b[N];
int f[N][N];

int main()
{
    int n, m;
    scanf("%d%s", &n, a + 1);   //字符串从1开始记录
    scanf("%d%s", &m, b + 1);   //字符串从1开始记录

    //初试化
    for(int i = 0; i <= n; i ++) f[i][0] = i;
    for(int i = 0; i <= m; i ++) f[0][i] = i;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if(a[i] == b[j])    //最后一位相同，不用变了
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m] << endl;
    return 0;
}
