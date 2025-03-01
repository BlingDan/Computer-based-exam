//
// Created by HUAWEI on 2025/3/1.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int primes[N], cnt;
int st[N];

void get_primes(int x)
{
    for(int i = 2; i <= x; i ++)
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
    int n;
    cin >> n;
    cout << n << endl;
    get_primes(N);
    cout << n << endl;

    int l = 0, r = cnt - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(primes[mid] >= n) {
            r = mid;
//            cout << "n:" << n << endl;
//            cout << primes[mid];
//            cout << "priems >= n\t" << "r = " << r << endl;
        }
        else {
            l = mid + 1;
//            cout << "primes < n\t" << "l = " << l << endl;
        }
    }

//    cout << l << endl;
    cout << primes[l] << endl;

    return 0;
}
