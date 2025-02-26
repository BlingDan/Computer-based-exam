//
// Created by HUAWEI on 2025/2/24.
//
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


int main()
{
    int m;
    cin >> m;
    while(m --)
    {
        int q;
        scanf("%d", &q);
        int n = 1;
        while(n * (n + 1) >> 1 < q)  n ++;

        q -= n * (n - 1) / 2;
        if(q == 1)  cout << 1 << endl;
        else cout << 0 << endl;
    }
}