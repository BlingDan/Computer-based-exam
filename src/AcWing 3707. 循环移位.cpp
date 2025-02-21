//
// Created by HUAWEI on 2025/2/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        if(a.size() > b.size()) {
            cout << "no" << endl;
            continue;
        }
        b.append(b);
        if(b.find(a) != string::npos)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
