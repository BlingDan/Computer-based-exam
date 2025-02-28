//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, k;
    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    cin >> k;
    while(k --)
    {
        int idx;
        cin >> idx;
        cout << a[idx] << endl;
    }

    return 0;
}
