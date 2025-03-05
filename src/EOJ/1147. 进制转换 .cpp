//
// Created by HUAWEI on 2025/3/3.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char get_ch(int n)
{
    if (n <= 9)
        return n + '0';

    return n - 10 + 'A';
}
int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        int n, r;
        cin >> n >> r;

        bool st = true;
        if(n < 0) st = false;
        n = abs(n);

        vector<int> v;
        while(n)
        {
            v.push_back(n % r);
            n /= r;
        }

        reverse(v.begin(), v.end());

        if(!st) cout << '-';
        for(int i = 0; i < v.size(); i ++)
            cout << get_ch(v[i]);

        cout << endl;
    }

    return 0;
}
