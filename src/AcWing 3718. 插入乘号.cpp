//
// Created by HUAWEI on 2025/2/18.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
string str;
long long ans;

// idx:乘号插入位置从0开始，cnt:已经插入的乘号数量，t：暂时的值，s:乘号之前的字符串
void dfs(int idx, int cnt, long long t, string s)
{
    if(idx == n - 1) {
        if(cnt == k)
        {
            t *= stoll(s);
            ans = max(ans, t);
        }
        return;
    }

    // 插入乘号
    dfs(idx + 1, cnt + 1, t * stoll(s), str.substr(idx + 1, 1));

    // 不插入乘号
    dfs(idx + 1, cnt, t, s + str[idx + 1]);
}
int main()
{
    cin >> n >> k >> str;
    dfs(0, 0, 1, str.substr(0, 1));

    cout << ans << endl;
    return 0;
}
