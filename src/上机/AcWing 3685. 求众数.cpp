//
// Created by HUAWEI on 2025/2/22.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<int, int>mp;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++)
    {
        int t;
        scanf("%d", &t);
        if(mp.count(t) == 0)
            mp.insert({t, 1});
        else
            mp[t] ++;

    }

    int num = 0;
    int pos = -1;
    for(auto it = mp.begin(); it != mp.end(); it ++) {
        if(it->second > num)
            num = it->second, pos = it->first;
        if(it->second == num)
            pos = min(pos, it->first);
    }

    cout << pos << endl;
    return 0;


}
