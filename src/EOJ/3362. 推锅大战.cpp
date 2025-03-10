//
// Created by HUAWEI on 2025/3/9.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
int main()
{
    int n;
    LL a= 0, b = 0, c = 0;

    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a += x;
        b += y;
        c += z;
    }

    b -= 10;

    if(a == 0 && b == 0 && c == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}