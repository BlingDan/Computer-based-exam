//
// Created by HUAWEI on 2025/2/20.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int a[N], cnt[N];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j < i; j ++)
            if(a[j] > a[i])
                cnt[a[i]] ++;

    int res = 0;
    for(int i = 1; i <= n; i ++) {
        cout << cnt[i] << ' ';
        res += cnt[i];
    }
    printf("\n%d", res);
    return 0;
}
