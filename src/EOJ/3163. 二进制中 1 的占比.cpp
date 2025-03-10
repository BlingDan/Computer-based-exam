//
// Created by HUAWEI on 2025/3/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0) return 1;
    if(b == 0)  return a;
    else return gcd(b, a % b);
}
int main()
{
    unsigned int t;
    scanf("%u", &t);
    int cnt = 0;
    while(t)
    {
        cnt ++;
        t = t & (t - 1);
    }

    int fenmu = gcd(cnt, 32);
    cout << cnt << "," << cnt / fenmu << ":" << 32 / fenmu << endl;
    return 0;
}
