//
// Created by HUAWEI on 2025/2/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int get_n(char x)
{
    if(x >= '0' && x <= '9')
        return x - '0';
    if(x >= 'A' && x <= 'F')
        return x - 'A' + 10;
}
char get_c(int x)
{
    if(x >= 0 && x <= 9)
        return x + '0';
    if(x >= 10 && x <= 15)
        return x - 10 + 'A';
}
int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        vector<int> ans;
        for(int i = 0; i < s1.size() && i < s2.size(); i ++)
            ans.push_back((get_n(s1[i]) + get_n(s2[i])) % 16);

        if(ans.size() < s1.size()) {
            for(int i = ans.size(); i < s1.size(); i ++)
                ans.push_back(get_n(s1[i]));
        }
        if(ans.size() < s2.size()) {
            for(int i = ans.size(); i < s2.size(); i ++)
                ans.push_back(get_n(s2[i]));
        }

        for(int i = ans.size() - 1; i >= 0; i --)
            cout << get_c(ans[i]);
        cout << endl;
    }
}
