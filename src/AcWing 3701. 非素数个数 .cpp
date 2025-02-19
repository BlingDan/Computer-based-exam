//
// Created by HUAWEI on 2025/2/19.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e7 + 10;
int primes[N], cnt;
bool st[N]; // st[i]存储i是否被筛掉
int s[N];

// 线性筛法让每个数只被筛掉依次
void get_primes(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;   // 保证了用最小的质因数，关键
        }
    }
}

int main()
{
    get_primes(N);
    for(int i = 1; i <= N; i ++) {
        if(st[i])
            s[i] = s[i - 1] + 1;
        else
            s[i] = s[i - 1];
    }

    int a, b;
    while(cin >> a >> b)
        cout << s[b] - s[a - 1] << endl;
    return 0;
}
