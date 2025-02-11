#include <iostream>
#include <algorithm>

using namespace std;
/**
 * sb题，sb状态转移方程，看不明白
 */
const int N = 1010;
const int mod = 1e9 + 7;

int f[N];

int main()
{
    int n;
    cin >> n;

    f[0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)    // sb状态转移方程，不知道怎么来的，j从i开始枚举，sbsbsbsb
        {
            f[j =
        }
}
