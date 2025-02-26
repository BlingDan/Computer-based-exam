//
// Created by HUAWEI on 2025/2/10.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int n, m;
int s[N];


int main()
{
    while(scanf("%d", &n )!= -1)
    {
        int ans = 0;
        for(int i = 0; i < n; i ++) scanf("%d", &s[i]);
        for(int i = 0; i < n;)
        {
            int j = i + 1;

            while(j < n && s[j] >= s[j - 1]) j ++;
            if(j - i >= 2)
                ans = max(ans, s[j - 1] - s[i]);
            i = j;
        }

        cout << ans << endl;
    }
    return 0;
}
