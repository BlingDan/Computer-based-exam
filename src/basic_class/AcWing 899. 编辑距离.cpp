#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1001;
char str[N][15];

/**
 * f[i][j] 将字符串a前i个字母变为字符串b前j个字母需要的最少次数
 * 1. 增加：将前i个字符变为前j - 1个字符，最后一步添加
 * 2. 删除：将前i - 1个字符变为前j个字符，最后一步删除
 * 3. 修改：将前i个字符变为前j - 1个字符，最后一步判断是否相等
 */

int miniDistance(char a[], char b[])
{
    int n = strlen(a), m = strlen(b);

    //初始化
    int f[15][15] = {0};
    for(int i = 0; i <= n; i ++) f[i][0] = i;
    for(int i = 0; i <= m; i ++) f[0][i] = i;

    //状态转移
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = min(f[i- 1][j] + 1, f[i][j - 1] + 1);
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        }

    return f[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        scanf("%s", str[i]);

    while(m --)
    {
        char op[15];
        int limit;
        cin >> op >> limit;

        int ans = 0;
        for(int i = 0; i < n; i ++)
        {
            if(miniDistance(str[i], op) <= limit)
                ans ++;
        }

        cout << ans << endl;
    }

    return 0;
}
