//
// Created by HUAWEI on 2025/2/20.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10010, MOD = 1e9 + 7;
int f[N];
char s1[N], s2[N];

int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q --)
    {
        memset(f, 0, sizeof f);
        scanf("%s%s", s1 + 1, s2 + 1);
        int n = strlen(s1 + 1), m = strlen(s2 + 1);

        vector<int> pos[26];
        for(int i = m; i >= 1; i --)
            pos[s2[i] - 'a'].push_back(i);

        f[0] = 1;
        for(int i = 1; i <= n; i ++)
            for(int j : pos[s1[i] - 'a'])
                f[j] = (f[j] + f[j - 1]) % MOD;

        cout << f[m] << endl;
    }
}
