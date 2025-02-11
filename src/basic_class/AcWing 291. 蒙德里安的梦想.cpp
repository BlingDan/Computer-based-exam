/**
 * 一刷2025年2月6日 预处理2部分和dp时候为什么i从1开始没搞明白
 * reference:https://lishizheng.blog.csdn.net/article/details/112706309
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 12, M = 1 << N;
LL f[N][M];     // 状态表示
bool st[M];     // 存储每个状态是否有连续的0，如果是奇数个0表示无效状态
vector<int> state[M];   // 二维数组记录合法状态

int main()
{
    int n, m;
    while(cin >> n >> m && n || m)
    {
        // 预处理1：
        // 对于每一列的每种状态，先预处理每列不能有奇数个连续的0
        for(int i = 0; i < (1 << n); i ++)
        {
            int cnt = 0; // 记录连续0的个数
            bool isValid = true;    // 某种状态没有奇数个连续的0则标记为true
            for(int j = 0; j < n; j ++) // 遍历每一行
            {
                if(i >> j & 1) {    // 当前第j位是否位1，如果是
                    if(cnt & 1) {   // 如果前面有奇数个0
                        isValid =false; // 状态不合法
                        break;
                    }
                    cnt = 0;
                } else {
                    cnt ++;
                }
            }
            if(cnt & 1) isValid = false;
            st[i] = isValid;
        }

        // 预处理2
        // 判断i-2列伸出来的与i-1列伸出来的是否有冲突
        for(int j = 0; j < (1 << n); j ++) // 遍历第i列的所有状态
        {
            state[j].clear();

            for(int k = 0; k < (1 << n); k ++) //遍历第i-1列所有状态
            {
                if((j & k) == 0 && st[j | k])
                    // j & k 看看两个有没有都突出来
                    // st[j | k] 没理解
                    state[j].push_back(k);
            }
        }

        // dp
        memset(f, 0, sizeof f);
        f[0][0] = 1;

        for(int i = 1; i <= m; i ++)    // 没理解
            for(int j = 0; j < (1 << n); j ++){
                for(auto item : state[j])
                    f[i][j] += f[i - 1][item];
            }

        cout << f[m][0] << endl;

    }

    return 0;
}
