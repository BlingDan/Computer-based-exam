#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;
int s[N];
int f[N][N];


int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <=n; i ++) {
        cin >> s[i];
        s[i] += s[i -1];
    }

    for(int len = 2; len <= n; len ++)  //枚举区间长度
        for(int i = 1; i + len - 1 <= n; i ++)  //枚举左端点
        {
            int j = i + len - 1; // 右端点
            f[i][j] = 0x3f3f3f3f;   // 计算最小值
            for(int k = i; k < j; k ++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }

    cout << f[1][n] << endl;
    return 0;
}
