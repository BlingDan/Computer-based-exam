//
// Created by HUAWEI on 2025/2/22.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;
int a[N], f[N];

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        if(i == 1)
            f[i] = 1;
        else if(i == 2)
            f[i] = 2;
        else
            f[i] = f[i - 1] + f[i - 2];
    }

    cout << f[n] << endl;
    return 0;
}