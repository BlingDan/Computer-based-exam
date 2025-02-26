//
// Created by HUAWEI on 2025/2/25.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 120;
int n, k;
int a[N];

bool check(int m)
{
    int res = 0;
    for(int i = 0; i < n; i ++)
        res += m / a[i];
    if(res <= k)
        return true;
    else
        return false;
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    int l = 0, r = 1e7;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid))  l = mid;
        else r = mid - 1;
    }

    cout << endl <<  l << endl;
    return 0;
}
