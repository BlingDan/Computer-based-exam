//
// Created by HUAWEI on 2025/2/28.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 12;
int n;
int ans;
bool st[N];

struct Treasure{
    char op;
    int ai, bi;
}treasure[N];


void dfs(int cnt, int x)
{
    if(cnt == n) {
        ans = max(ans, x);
        return;
    }

    for(int i = 0; i < n; i ++) {
        if(!st[i]) {
            st[i] = true;
            auto t = treasure[i];
            char op = t.op;
            int ai = t.ai, bi = t.bi;

            int new_x = x;
            if(op == '&')
                new_x = (x & ai) + bi;
            else if(op == '|')
                new_x = (x | ai) + bi;
            else
                new_x = (x ^ ai) + bi;

            dfs(cnt + 1, new_x);
            st[i] = false;

        }
    }


}
int main()
{
    cin >> n;

    for(int i = 0; i < n; i ++)
        cin >> treasure[i].op >> treasure[i].ai >> treasure[i].bi;

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}
