//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    while(n > 0)
    {
        n = n >> 1;
        cnt ++;
    }
    cout << cnt << endl;
    return 0;
}
