//
// Created by HUAWEI on 2025/3/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    char ch;
    int t;
    cin >> ch;

    if(ch == 'D')
    {
        set<int, greater<>> s;
        while(cin >> t)
            s.insert(t);

        for(auto it:s)
            cout << it << ' ';
        cout << endl;
    }else {
        set<int> s;
        while(cin >> t)
            s.insert(t);

        for(auto it:s)
            cout << it << ' ';
        cout << endl;
    }

    return 0;
}
