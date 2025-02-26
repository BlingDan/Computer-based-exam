//
// Created by HUAWEI on 2025/2/24.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k;

int main()
{
    scanf("%d%d%d", &m, &n, &k);

    int i = 1, j = 1;

    while(k --)
    {
        if(i == m + 1)  i = 1;
        if(j == n + 1)  j = 1;
        cout << i << ' ' << j << endl;
        i ++;
        j ++;
    }
    return 0;
}