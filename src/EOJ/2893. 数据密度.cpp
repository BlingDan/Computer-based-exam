//
// Created by HUAWEI on 2025/3/1.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    getchar();

    while(n --)
    {
        string line;
        getline(cin, line);

        int cnt = 0;
        for(int i = 0; i < line.size(); i ++)
        {
            for(int j = 0; j < 8; j ++)
                if(line[i] >> j & 1)
                    cnt ++;
        }

        int t = gcd(cnt, 8 * line.size());
        cout << cnt / t << "/" << 8 * line.size() / t << endl;
    }
}
