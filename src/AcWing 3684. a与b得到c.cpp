//
// Created by HUAWEI on 2025/2/22.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

int main()
{
    LL a, b, c;
    while(scanf("%lld%lld%lld", &a, &b, &c) != -1)
    {
        bool val = false;
        if(a + b == c)
            val = true;
        else if(a - b == c || b - a == c)
            val = true;
        else if(a * b == c)
            val = true;
        else if(a == b * c || b  == a * c)
            val = true;
        else
            val = false;

        cout << (val ? "YES" : "NO") << endl;
    }
}