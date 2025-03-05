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

    for(int cnt = 0; cnt < T; cnt ++)
    {
        int n;
        cin >> n;

        if(n == 0) {
            printf("case #%d:\n", cnt);
            cout << "0 0" << endl;
            continue;
        }

        vector<int> v;
        int t = n;
        while(t)
        {
            v.push_back(t % 2);
            t /= 2;
        }

        reverse(v.begin(), v.end());

        printf("case #%d:\n", cnt);
        for(int i = 0; i < v.size(); i ++)
            cout << get_ch(v[i]);

        cout << ' ';

        v.clear();
        t = n;
        while(t)
        {
            v.push_back(t % 16);
            t /= 16;
        }

        reverse(v.begin(), v.end());

        for(int i = 0; i < v.size(); i ++)
            cout << get_ch(v[i]);

        cout << endl;
    }

    return 0;
}
