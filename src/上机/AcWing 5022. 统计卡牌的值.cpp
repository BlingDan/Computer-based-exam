//
// Created by HUAWEI on 2025/2/10.
//
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dic = {
        {'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0},
        {'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4}
};

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while(n --)
    {
        string str;
        cin >> str;

        for(int i = 0; i < str.size(); i ++) {
            res += dic[str[i]];
        }
    }
    cout << res << endl;
}
