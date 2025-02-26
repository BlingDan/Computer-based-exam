//
// Created by HUAWEI on 2025/2/10.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int n, m, k;
int a[N], d[N];

int main()
{
    while(scanf("%d%d%d", &n, &m, &k) != -1)
    {
        memset(d, 0, sizeof d);
        memset(a, 0, sizeof a);
        for(int i = 0; i < m; i ++)
            cin >> a[i];

        for(int i = 0; i < m; i ++)
        {
            int l = max(1, a[i] - k);
            int r = min(n, a[i] + k);
            d[l] ++;
            d[r + 1] --;
        }

        int count = 0;
        int current = 0;
        for(int i = 1; i <= n; i ++)
        {
            current += d[i];
            if(current == 0) {
                count ++;
                current = 1;
                int r = min(n, i + 2 * k);
                d[i] ++;
                d[r + 1] --;
            }
        }

        cout << count << endl;
    }
}
