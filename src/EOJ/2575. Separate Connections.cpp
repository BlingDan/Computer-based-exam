//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N;

int n;
char matrix[N][N];
int f[M];   // f[state] 在状态state下的最大匹配对数

int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        memset(f, 0, sizeof f);

        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                cin >> matrix[i][j];


        for(int st = 0; st < 1 << n; st ++)
        {
            for(int i = 0; i < n; i ++)
            {
                if(!(st >> i & 1)) {
                    for(int j = i + 1; j < n; j ++) {
                        if(!(st >> j & 1) && matrix[i][j] == 'Y') {
                            int cur = st | 1 << i | 1 << j;
                            f[cur] = max(f[cur], f[st] + 1);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int st = 0; st < 1 << n; st ++)
            ans = max(ans, f[st]);

        cout << ans * 2 << endl;
    }

    return 0;
}
