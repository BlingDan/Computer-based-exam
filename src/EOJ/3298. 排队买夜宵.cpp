//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        string str;
        cin >> str;

        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = 0; i < str.size(); i ++) {
            if(str[i] == '1')
                cnt1 ++;
            else
                cnt0 ++;
        }

        cout << abs(cnt1 - cnt0) << endl;
    }

    return 0;
}
