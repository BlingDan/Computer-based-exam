#include <iostream>

/**
 * 扩展欧几里得算法没搞明白 一刷2025年1月24日
 */
using namespace std;

int extend_gcd(int a, int b, int &x, int &y)
{
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extend_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int main()
{
    int n, a, b;
    cin >> n;
    while(n --)
    {
        scanf("%d%d", &a, &b);
        int x, y;
        extend_gcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
}
