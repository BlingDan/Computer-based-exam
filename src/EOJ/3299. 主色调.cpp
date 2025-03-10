//
// Created by HUAWEI on 2025/3/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;
int color[N];

int main()
{
    int n;
    while(cin >> n) {
        vector<int> ans(n + 10, 0);  // 每种颜色为主色调的区间个数

        memset(color, 0, sizeof color);
        for (int i = 1; i <= n; i++)
            cin >> color[i];

        for (int i = 1; i <= n; i++) {
            vector<int> res(n + 10, 0);
            int m_c = -1;   // 维护的最大值颜色
            int m_cnt = 0;    // 最大值出现的次数

            for (int j = i; j <= n; j++) {
                int cur = color[j];
                res[cur]++;

                if (res[cur] > m_cnt) {
                    m_cnt = res[cur];
                    m_c = cur;
                } else if (res[cur] == m_cnt && m_c > cur) {
                    m_c = cur;
                }

                if(m_c >= 1 && m_c <= n)
                    ans[m_c]++;
            }


        }

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];
            if(i != n)  cout << ' ';
            else cout << endl;
        }
    }

    return 0;
}
