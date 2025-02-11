#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int n;
int a[N];
int f[N];

void dp()
{
    int res = 0;   //res 应该初始化为0，同时f[i]初始化为1保证至少有一个子序列是其本身
    //不能初始化为随便的一个负数
    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j ++)    // j是从0开始的，保证f[]数组符合定义，j是i的前驱
        {
            if(a[i] > a[j])
            {
                f[i] = max(f[i], f[j] + 1);
                res = max(res, f[i]);
            }
        }
    }

    cout << res;
    return;

}
int main()
{
//    memset(f, 1, sizeof f);  memset是按照字节初试话的 这里的1会被解释为0x01
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    dp();
    return 0;
}
