#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;
int n;
int f[N][N];
int w[N][N];

void dp()
{
    for(int i = 1; i <= n; i ++)
        f[n][i] = w[n][i];

    for(int i = n - 1; i >= 1; i --)
        for(int j = 1; j <= i; j ++)
        {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + w[i][j];
        }

    cout << f[1][1] << endl;
    return;
}
int main()
{
    cin >> n;
    for(int i = 1;i <= n; i ++)
        for(int j = 1; j <= i; j ++)
            cin >> w[i][j];
    dp();
    return 0;
}
