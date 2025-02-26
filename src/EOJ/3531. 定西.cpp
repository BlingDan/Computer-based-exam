//
// Created by HUAWEI on 2025/2/24.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int a[N], f[N];
bool st[N];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i ++) {
        int t;
        scanf("%d", &t);
        st[t] = true;
    }

    if(!st[1]) f[1] = 1;
    if(!st[2]) f[2] = f[1] + 1;
    if(!st[3]) f[3] = f[1] + f[2] + 1;

    for(int i = 4; i <= n; i ++)
    {
        if(st[i])
            f[i] = 0;
        else {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
    }

    cout << f[n] << endl;
    return 0;
}
