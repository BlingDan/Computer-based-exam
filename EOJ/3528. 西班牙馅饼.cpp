//
// Created by HUAWEI on 2025/2/24.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        vector<int> t;
        for(int j = 0; j < m; j ++)
        {
            int x;
            scanf("%d", &x);
            t.push_back(x);
        }

        sort(t.begin(), t.end(), greater<int>());
        res += t.front();
    }
    cout << res << endl;
    return 0;
}
