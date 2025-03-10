//
// Created by HUAWEI on 2025/3/9.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1010;
vector<int> v[10010];   // 第i门课的所有上课时间
unordered_map<string, int> mp;
int n;

int main()
{
    cin >> n;
    int idx = 1;
    for(int i = 1; i <= n; i ++)
    {
        string s;
        int t;
        cin >> s >> t;
        if(mp.count(s) == 0)
            mp[s] = idx ++;
        v[mp[s]].push_back(t);
    }


    for(int i = 1; i <= n; i ++)
    {
        sort(v[i].rbegin(), v[i].rend());
        while(v[i].size() > 2)
            v[i].pop_back();
    }

    int ans = 0;
    for(int i = 1; i < idx; i ++)
    {
        for(auto it:v[i])
            ans += it;
    }
    cout << ans << endl;
    return 0;
}