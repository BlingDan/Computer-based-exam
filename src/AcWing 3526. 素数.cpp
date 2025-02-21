//
// Created by HUAWEI on 2025/2/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
bool st[N];
int primes[N], cnt;
int n;

void get_prime(int x)
{
    for(int i = 2; i < x; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] <= x / i; j ++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    get_prime(N);
    while(scanf("%d", &n) != -1)
    {
        int flag = 0;
        for(int i = 0; i < cnt; i ++)
        {
            if(primes[i] >= n)   break;

            int t = primes[i] % 10;
            if(t == 1) {
                flag = 1;
                cout << primes[i] << ' ';
            }
        }
        if(!flag)
            cout << -1 << endl;
        else cout << endl;
    }

    return 0;

}
