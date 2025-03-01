//
// Created by HUAWEI on 2025/2/28.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 0;
    while(n) {
        if(n & 1) res ++;
        n /= 2;
    }
    cout << res << endl;

    return 0;
}
