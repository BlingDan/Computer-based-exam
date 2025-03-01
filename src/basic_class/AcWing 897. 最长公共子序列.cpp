#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 1010;

char a[N], b[N];
int n, m;
int f[N][M];

void dp()
{
    for(int i = 1; i <= n; i ++)
        for(int j =1; j <= m; j ++)
        {
            if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1]  + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }

    cout << f[n][m] << endl;
    return;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];

    dp();
    return 0;

}
