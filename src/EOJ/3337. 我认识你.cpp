//
// Created by HUAWEI on 2025/3/2.
//
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 40010;
bitset<N> friends[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i ++)
    {
        int u, v;
        cin >> u >> v;
        friends[u].set(v);
        friends[v].set(u);
    }

    int q;
    cin >> q;
    while(q --)
    {
        int s, t;
        cin >> s >> t;

        cout << (friends[s] & friends[t]).count() << endl;
    }

    return 0;
}
