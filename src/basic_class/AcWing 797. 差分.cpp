#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N], d[N];
int n, m;
int l, r, c;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) d[i] = a[i] - a[i - 1];

    for(int i = 0; i < m; i ++)
    {
        scanf("%d%d%d", &l, &r, &c);
        d[l] += c;
        d[r + 1] -=c;
    }

    // a1 = a0 + d1,
    // a2 = a1 + d2 = a0 + d1 + d2
    // a3 = a2 + d3 = a1 + d2 + d3 = a0 + a1 + a2 + a3
    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        res += d[i];
        printf("%d ", res);
    }
    return 0;
}
