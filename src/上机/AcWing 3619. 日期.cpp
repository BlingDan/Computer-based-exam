//
// Created by HUAWEI on 2025/3/1.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> mp = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
unordered_map<int, int>day_per_month {
        {4, 30},
        {6, 30},
        {9, 30},
        {11, 30},
        {5, 31},
        {7, 31},
        {8, 31},
        {10, 31},
        {12, 31},
};

int get_total_dat(int month, int day)
{
    // 2012.04.12 -> 周四
    if(month == 4) return day - 12;

    int res = 19; //从5月1日开始计算
    for(int i = 5; i < month; i ++)
        res += day_per_month[i];

    return res + day - 1;
}
int main()
{
    int m, d;
    cin >> m >> d;

    int ans = get_total_dat(m, d);
//    cout << ans << endl;
    ans = (ans + 3) % 7;
//    cout << ans << endl;
    cout << mp[ans] << endl;

    return 0;
}
