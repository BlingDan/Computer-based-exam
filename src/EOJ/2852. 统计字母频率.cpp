//
// Created by HUAWEI on 2025/3/5.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> mp;
int res = 0;
string str;

int main()
{
    for(int i = 0; i < 26; i ++)
        mp.insert({i, 0});

    getline(cin, str);

    for(int i = 0; i < str.size(); i ++){
        if(str[i] == ' ')
            continue;
        mp[str[i] - 'a'] ++;
        res ++;
    }

    int t = -1;
    int ch = 0x3f3f3f3f;
    for(auto it: mp)
    {
        if(it.second > t) {
            t = it.second;
            ch = it.first;
        }

        if(it.second == t) {
            ch = min(ch, it.first);
        }
    }

//    cout << t << endl;
//    cout << res <<endl;
    double fre = (double)t / res;
    printf("%c %.2f", ch + 'a', fre);

}
