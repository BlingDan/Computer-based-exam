//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        long long x = 1;
        for(int i = n; i >= n - 3; i --)
            x *= i;

        cout << x / 24 << endl;
    }
}
