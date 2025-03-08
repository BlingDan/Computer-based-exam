//
// Created by HUAWEI on 2025/3/7.
//
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//const int N = 20010;
//int primes[N], cnt;
//bool st[N];
//
//void get_primes(int x)
//{
//    for(int i = 2; i <= x; i ++)
//    {
//        if(!st[i]) primes[cnt ++] = i;
//        for(int j = 0; primes[j] <= x / i; j ++)
//        {
//            st[primes[j] * i] = true;
//            if(i % primes[j] == 0) break;
//        }
//    }
//}
//
//int main()
//{
//    get_primes(N);
//
//    int n;
//    int a, b;
//
//
//    while(cin >> n)
//    {
//        int l = 0, r = cnt - 1;
//        while(l < r)
//        {
//            int mid = l + r >> 1;
//            if(primes[mid] >= n) r = mid;
//            else l = mid + 1;
//        }
//
//        int bound = l;
//
////        cout << "bound:" << primes[bound] << endl;
//
//        for(int i = (bound + 1) / 2; i >= 0; i --)
//        {
//            if(!st[n - primes[i]]) {
//                a = min(primes[i], n - primes[i]);
//                b = max(primes[i], n - primes[i]);
//                break;
//            }
//        }
//
//        cout << a << ' ' << b << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010;
int primes[N], cnt;
bool st[N];

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
    get_primes(N);

    int n;
    int a, b;

    while(cin >> n)
    {
        int best_a = -1, best_b = -1;
        int max_product = -1;

        for (int i = 0; primes[i] <= n / 2 && i < cnt; ++i) // 遍历 primes 数组，直到质数超过 n/2
        {
            int current_a = primes[i];
            int current_b = n - current_a;
            if (!st[current_b]) // 检查 b 是否为质数
            {
                if (current_a * current_b > max_product)
                {
                    max_product = current_a * current_b;
                    best_a = current_a;
                    best_b = current_b;
                }
            }
        }
        cout << best_a << ' ' << best_b << endl;
    }

    return 0;
}
