//
// Created by HUAWEI on 2025/2/18.
//
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1010;
int p[N];
int n, m;

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        p[i] = i;
    }

    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(find(a) != find(b))
            p[find(a)] = find(b);
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(p[i] == i)
            ans ++;
    }

    cout << ans - 1 << endl;
    return 0;
}