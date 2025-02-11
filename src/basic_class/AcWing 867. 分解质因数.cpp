#include <iostream>

using namespace std;


/**
 * 与AcWing 866. 试除法判定质数   对比，本题的循环次数在logn ~ sqrt(n)之间而判定质数循环条件一定是sqrt(n)
 *
 * 注意最后的处理，循环之后，最多剩下一个大于sqrt(n)的数
 * @param x
 */
void divide(int x)
{
    if(x < 2) return;

    for(int i = 2; i <= x / i; i ++)
    {
        if(x % i == 0)
        {
            int k = 0;
            while(x % i == 0)
            {
                k ++;
                x /= i;
            }
            cout << i << ' ' << k << endl;
        }
    }

    //循环之后，最多剩下一个大于sqrt(n)的数 如6 循环之后剩下3 直接输出即可
    if(x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int m;
        cin >> m;
        divide(m);
    }

    return 0;
}