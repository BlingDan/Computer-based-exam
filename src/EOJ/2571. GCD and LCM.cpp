//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return  gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        int a, b;
        cin >> a >> b;
        int GCD = gcd(a, b);
        long long LCM = (long long) a * b / GCD;

        cout << GCD << ' ' << LCM << endl;
    }

    return 0;
}
