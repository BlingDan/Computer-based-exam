//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 10010;
int primes[N], cnt;
bool st[N];

void get_primes(int x)
{
    for(int i = 2; i <= x; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;

        for(int j = 0; primes[j] <= x / i; j ++)
        {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }

    return;
}

int main()
{
    int T;
    cin >> T;

    get_primes(N);
    st[1] = 1;

//    for(int i = 0; i < cnt; i ++)
//        cout << primes[i] << ' ';
//    cout << endl;

//    cout << st[1] << endl;
    while(T --)
    {
        int n;
        cin >> n;

        int res = 0;
        for(int i = 1; i <= n; i ++)
        {
            int a = i, b = n + 1 - i;
            if(!st[a] && !st[b])
                res ++;
        }

        cout << res << endl;
    }

    return 0;
}
