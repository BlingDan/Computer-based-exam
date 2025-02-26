//
// Created by HUAWEI on 2025/2/23.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> a, b, c;
    int n, m;
    cin >> n >> m;

    int t;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &t);
        a.insert(t), c.insert(t);
    }
    for(int i = 0; i < m; i ++) {
        scanf("%d", &t);
        b.insert(t), c.insert(t);
    }

    int ans = 0;
    for(auto it : c) {
        if(a.count(it) && b.count(it))
            ans ++;
    }

    cout << ans << ' ' << c.size() << endl;
    return 0;

}
