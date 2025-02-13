#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 110;
int a[N];
int n, l, r;

int main()
{
    cin >> n >> l >> r;
    int m = 0x3f3f3f3f;

    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    int ans = 0x3f3f3f3f;
    for(int i = l; i <= r; i ++)
        ans = min(ans, a[i]);
    cout << ans << endl;
    return 0;
}
