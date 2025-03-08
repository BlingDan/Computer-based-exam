//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string s, s1;
    int T;
    cin >> T;

    for(int q = 0; q < T; q ++)
    {
//        cin >> s >> s1;
//
//
//        auto pos = s.find(s1);
//        while(pos != string::npos)
//        {
//            cout << "s:" << s << "\n" << "pos:" << pos << "\n";
//            s.erase(pos, s1.length());
//            pos = s.find(s1);
//        }
//        cout << "case #" << q << ":\n" << s << "\n";
        cin >> s >> s1;
        int n = s.size(), m = s1.size();
        printf("case #%d:\n", q);
        for(int i = 0; i < n; i ++)
        {
            if(s.substr(i, m) == s1)
                i = i + m - 1;
            else
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
