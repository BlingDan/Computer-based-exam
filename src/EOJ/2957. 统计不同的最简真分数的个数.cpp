//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 1010;
set<int> a;

int gcd(int a, int b)
{
    if(b == 0)  return a;
    else return gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;

    for(int count = 0; count < T; count ++)
    {
        a.clear();
        int n;
        cin >> n;

        for(int i = 0; i < n; i ++) {
            int num;
            cin >> num;
            a.insert(num);
        }

        int res = 0;
        for(auto i = a.begin(); i != a.end(); i ++)
            for(auto j = next(i); j != a.end(); j ++)
            {
                int k = *i, m = *j;
                if(k < m && gcd(k, m) == 1)
                    res ++;
            }

        cout << "case #" << count << ":\n" << res << "\n";

    }
}
