//
// Created by HUAWEI on 2025/2/26.
//
#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = gcd(gcd(a, b), c);
    cout << ans << endl;
    return 0;
}
