#include <iostream>

using namespace std;
/**
 * 多重背包问题是一个物品可以选择多次与01背包问题很类似
 * 将最多选择n个的物品分解为n个只能选择一次的物品就转化为了01背包问题
 */
const int N = 110;
int n, m;
int v[N], w[N], count[N];
int f[N];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> count[i];

    for(int i = 1; i <= n; i ++)
        for(int j = m; j >= 0; j --)
            for(int k = 0; k <= count[i] && k <= j / v[i]; k ++)
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);

    cout << f[m] << endl;

    return 0;
}
