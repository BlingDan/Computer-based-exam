#include <iostream>

using namespace std;

const int N = 1010, V = 1010;


/**
 * 01 背包问题优化版本
 * 对dp问题的优化是对代码的优化不是算法逻辑的优化
 * 优化版本中尝试将二维数组f[N][V]优化为一维数组
 */
int v[N], w[N];
//int f[N][V];
int f[V];
void dp(int n, int m)
{
    //观察到在i的遍历时候是按照顺序的从1->i计算i的时候i-1已经确定了，从这个角度去掉第一维

//    假设有以下输入：
//    n = 3, m = 5
//    v = [2, 3, 4]  // 物品体积
//    w = [3, 4, 5]  // 物品价值
//    从小到大遍历的错误情况
//    如果 j 从小到大遍历：
//
//    当 i = 1（物品体积为 2，价值为 3）时：
//    j = 2：f[2] = max(f[2], f[0] + 3) = 3
//    j = 4：f[4] = max(f[4], f[2] + 3) = 6（这里 f[2] 已经被更新为 3，导致物品 1 被重复选择）
//    最终结果错误。
//
//    从大到小遍历的正确情况
//    如果 j 从大到小遍历：
//    当 i = 1（物品体积为 2，价值为 3）时：
//    j = 4：f[4] = max(f[4], f[2] + 3) = 3（f[2] 仍然是初始值 0）
//    j = 2：f[2] = max(f[2], f[0] + 3) = 3
//    最终结果正确。
    for(int i = 1; i <= n; i ++)
        for(int j = m; j >= v[i]; j --)
        {
            //situation 1:不选择第i件物品
            f[j] = f[j];
            //situation 2:选择第i件物品
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }

    cout << f[m] << endl;
    return ;



    // f[i][j] 前i个物品中体积不超过j的最大的总价值
//    for(int i = 1; i <= n; i ++)
//        for(int j = 0; j <= m; j ++)
//        {
//            //01背包问题中状态转移对应了两种情况
//
//            //situation 1: 不选择第i件物品
//            f[i][j] = f[i - 1][j];
//            if(j - v[i] >= 0)
//                //situation 2: 选择第i件物品，二者取max
//                f[i][j] = max(f[i][j], f[i  - 1][j - v[i]] + w[i]);
//        }
//
//    cout << f[n][m] << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i =  1; i <= n; i ++)
    {
        cin >> v[i] >> w[i];
    }

    dp(n, m);

    return 0;


}