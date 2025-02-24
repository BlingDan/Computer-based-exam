//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int n, d;
int a[N];

int main()
{
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    int res = 1;
    int b= a[0];
    for(int i = 1; i < n; i ++)
    {
        if(a[i] - b >= d) {
            b = a[i];
            res ++;
        }
    }

    cout << res << endl;
    return 0;
}
