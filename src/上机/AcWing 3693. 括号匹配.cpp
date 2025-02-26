//
// Created by HUAWEI on 2025/2/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

unordered_map<char, char> mp {
        {'<','>'},
        {'(',')'},
        {'{','"}'},
        {'[',']'},
};

set<char> op {
        '<','(','{','[',
};

int main()
{
    stack<char> st;
    string str;
    cin >> str;
    int flag = 1;
    for(int i = 0; i < str.size(); i ++)
    {
        char t = str[i];
        if(op.count(t))
            st.push(t);
        else {
            if(st.empty() || mp[st.top()] != t) {
                flag = 0;
                break;
            }
            st.pop();
        }
    }

    cout << (flag ? "yes" : "no") << endl;
    return 0;
}
