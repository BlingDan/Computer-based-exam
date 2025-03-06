//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<int, int> mp{
        {0, -1},
        {1, 31}, {3, 31},{5, 31},{7, 31},{8, 31},{10, 31},{11, 30},
        {4, 30}, {6, 30},{9, 30},{12, 31},
        {2, 28}
};

int get_num(string str)
{
    int res = 0;
    for(char i : str)
        res = res * 10 + (i - '0');

    return res;
}

int main()
{
    string str;
    cin >> str;

    int month = get_num(str.substr(5, 2));
    int day = get_num(str.substr(8, 2));

    int ans = 0;
    for(int i = 1; i < month; i ++)
        ans += mp[i];

    ans += day;

    if(ans == 0 || mp[month] < day || month > 12 || day > 31)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
