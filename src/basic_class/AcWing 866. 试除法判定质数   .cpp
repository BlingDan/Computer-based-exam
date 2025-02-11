#include <iostream>

using namespace std;
/**
 * 用除数法判断是否为质数，一个数如果不是质数，因子是成对出现的。将算法复杂度压缩到n^1/2
 * 在判断条件中i <= x / i 不能写成i* i <= x 造成上溢出。不能在循环条件里写sqrt(x)每次循环来一次很慢
 * @param x
 * @return
 */
bool is_prime(int x)
{
    if(x < 2) return false;

    for(int i = 2; i <= x / i; i ++)
    {
        if(x % i == 0)
            return false;
    }

    return true;
}
int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int m;
        cin >> m;
        if(is_prime(m))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}