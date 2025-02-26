//
// Created by HUAWEI on 2025/2/19.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30;

int f[N];

int main()
{
    f[0] = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        if(i == 1)
            f[i] = f[0];
        else if(i == 2)
            f[i] = f[1] + f[0];
        else
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }

    cout << f[n] << endl;
    return 0;
}