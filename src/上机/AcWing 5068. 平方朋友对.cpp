//
// Created by HUAWEI on 2025/2/14.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int f(int x)
{
    return x * x / 1000;
}
int main()
{
    int n, ma;
    cin >> n >> ma;

    // 枚举所有的B
    int cnt = 0;
    int mb =  sqrt((ma + n - 1) * 1000 + 999);
    for(int b = 32; b <= mb; b ++)
    {
        int a = f(b);
        bool success = true;
        for(int i = 1 ; i < n; i ++) {
            if(a + i != f(b + i)) {
                success = false;
                break;
            }
        }

        if(success) {
            cnt ++;
            cout << a << ' ' << b << endl;
        }
    }

    if(!cnt)
        cout << "No Solution." << endl;

    return 0;
}
