//
// Created by HUAWEI on 2025/2/22.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes[cnt ++] =i;
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}


int main()
{
    int a, b;
    cin >> a >> b;
    get_primes(N);

//    for(int i = a; i <= b; i ++) {
//        if(st[i]) cout << i << ' ';
//    }
//    cout << endl;
    int len = 0, res = 0, idx;
    for(int i = b; i >= a; i --)
    {

        if(st[i]) {
            res ++;
        } else {
            if(len <= res) {
//                cout << i + 1 << endl;
                len = res;
                idx = i + 1;
            }
            res = 0;
        }
    }
    if(len <= res)
        len = res, idx = a;

    for(int i = idx; i < idx + len; i ++)
        cout << i << ' ';
    cout << endl;
    return 0;
}
