//
// Created by HUAWEI on 2025/3/3.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

const int N = 10;
int m[N];
unordered_map<int, int>mp{
        {1, 100},
        {2, 50},
        {3, 20},
        {4, 10},
        {5, 5},
        {6, 1}
};

int main()
{
    int T;
    cin >> T;

    for(int cnt = 1; cnt <= T; cnt ++)
    {
        memset(m, 0, sizeof m);
        int n;
        cin >> n;

        for(int i = 1; i <= 6; i ++)
        {
            if(n == 0)  break;
            if(mp[i] > n) continue;
            m[i] = n / mp[i];
            n %= mp[i];
        }

        printf("case #%d:\n", cnt - 1);
        for(int i = 1; i <= 6; i ++)
            cout << m[i] << ' ';
        cout << endl;
    }

    return 0;
}
