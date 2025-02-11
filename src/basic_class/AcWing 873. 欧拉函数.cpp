#include <iostream>
#include <algorithm>

using namespace std;

int divide(int x)
{
    if(x == 1) return 1; //1的欧拉函数为1

    int res = x;
    for(int i = 2; i <= x / i; i ++)
    {
        if(x % i == 0)
        {
            //res *=  (0 - 1/p)
            res -= res / i;
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1)
        res -= res / x;
    return res;
}
int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int a;
        cin >> a;
        cout << divide(a) << endl;
    }

    return 0;
}
