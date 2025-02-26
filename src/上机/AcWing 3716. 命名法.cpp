//
// Created by HUAWEI on 2025/2/20.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        for(int i = 0; i < str.size(); i ++)
        {
            char t = str[i];
            if(t >= 'a' && t <= 'z')
                cout << t;
            else {
                cout << "_" << (char)('a' + t - 'A') ;
            }
        }
        cout << endl;
    }
    return 0;
}
