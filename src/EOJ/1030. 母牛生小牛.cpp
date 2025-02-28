//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 60;

int f[N];

int main()
{
    f[1] = 1,
            f[2] = 1;
    f[3] = 1;

    int n;
    while(cin >> n)
    {
        if(n == 0)  break;

        for(int i = 4; i <= n; i ++)
            f[i] = f[i - 1] + f[i - 3];

        cout << f[n] << endl;
    }
}
