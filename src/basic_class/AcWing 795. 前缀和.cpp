#include <iostream>
//#include <algorithm>

using namespace std;

const int N = 1e5+ 10;
int a[N], sum[N];
int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
//        cin >> a[i];
        scanf("%d", &a[i]);
//        sum[i] = sum[i -1] + a[i];
    }

    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i -1] + a[i];

    for(int i = 0; i < m; i ++)
    {
        int l, r;
//        cin >> l >> r;
        scanf("%d%d", &l ,&r);
//        cout << sum[r] - sum[l] + a[l] << endl;
//        cout << sum[r] - sum[l - 1] << endl;
        printf("%d\n", sum[r] - sum[l - 1]);
    }
}