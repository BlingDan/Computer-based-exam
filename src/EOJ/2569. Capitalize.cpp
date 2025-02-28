//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        for(int i = 0; i < str.size(); i ++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 'a'+ 'A';
        }

        for(int i = 0; i < str.size(); i ++)
            cout << str[i];
        cout << ' ';
    }

    return 0;
}
