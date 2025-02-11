#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
int n;

LL quick_pow(LL a, LL b, LL p)
{
    LL res = 1;
    a = a % p;

    while (b > 0)
    {
        if (b & 1) { // 如果当前 b 是奇数
            res = (LL)res * a % p; // 将当前的 a 乘到结果中
        }
        a = (LL)a * a % p; // 将 a 平方
        b = b >> 1; // 将 b 右移一位
    }

    return res;
}

int main()
{
    cin >> n; // 输入数据组数
    for (int i = 0; i < n; i++)
    {
        LL a, b, p;
        scanf("%lld%lld%lld", &a, &b, &p); // 输入 a, b, p
        LL res = quick_pow(a, b, p);

        cout << res << endl; // 输出 a^b mod p
    }
    return 0;
}
