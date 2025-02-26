//
// Created by HUAWEI on 2025/2/18.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long LL;
const int N = 110;
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    string res;
    for(int len = min(s1.length(), s1.length()); len; len --)
    {
        for(int i = s1.length() - len; i >= 0; i --)
        {
            for(int j = s2.length() - len; j >= 0; j --)
            {
                string a = s1.substr(i, len);
                string b = s2.substr(j, len);
                if(a == b) {
                    res = a;
                    break;
                }
            }
            if(res.length()) break;
        }
        if(res.length()) break;
    }

    cout << res.length() << endl;
    cout << res << endl;
    return 0;
}
