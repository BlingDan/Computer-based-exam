//
// Created by HUAWEI on 2025/3/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>
// 注意数据的读入，读入的是long long 类型的数！！！
using namespace std;

const int N = 10010;
typedef long long LL;
typedef unsigned long long ULL;

struct Num {
    LL x;
    int dig;

    bool operator< (const Num& other) & {
        if(dig != other.dig)
            return dig > other.dig;
        else
            return x < other.x;
    }
}num[N];

int get_dig(LL x)
{
    int res = 0;
    ULL t = (ULL)x;
    for(int i = 0; i < 64; i ++)
        if(t >> i & 1)
            res ++;

    return res;
}

int n, T;

int main()
{
    cin >> T;

    for(int count = 0; count < T; count ++)
    {
        memset(num, 0, sizeof 0);

        cin >> n;
        for(int i = 0; i < n; i ++) {
            scanf("%lld", &num[i].x);
            num[i].dig = get_dig(num[i].x);
//            cout << num[i].dig << endl;
        }

        sort(num, num + n);

        printf("case #%d:\n", count);
        for(int i = 0; i < n; i ++)
            cout << num[i].x << ' ';
        cout << endl;
    }
}
