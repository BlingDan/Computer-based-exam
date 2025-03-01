//
// Created by HUAWEI on 2025/2/28.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int C;
    cin >> C;

    while(C --)
    {
        int n;
        cin >> n;

        int res = 0;
        for(int i = 0; i <= n - 1; i ++)
            res += 4 * (2 * i + 1) * (n - i);

        cout << res << endl;
    }

    return 0;
}
