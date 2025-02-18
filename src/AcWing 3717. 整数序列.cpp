//
// Created by HUAWEI on 2025/2/18.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e7 + 10;
vector<int> v;

int main()
{
    int q;
    cin >> q;
    int n = 2 * q;
    for(int i = 2; i <= n / i; i ++)
    {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i)
                v.push_back(n / i);
        }
    }

    /**
     * a + (a + 1) + (a + 2) + ... + (a + k) = n
     * (2a + k)(k + 1) = 2n
     */
    sort(v.begin(), v.end(), greater<int>());
//    for(auto item: v) cout << item << ' ';
//    cout << endl;
    int flag = 0;
    for(auto item: v)
    {
        int k = item - 1;
        int a = n / item - k;
        if(a % 2 == 0 && a > 0){
            flag = 1;
//            cout << "item:" << item << endl;
            a /= 2;
            for(int i = a;i <= a + k; i ++)
                cout << i << ' ';
            cout << endl;
        }
    }
    if(!flag) cout << "NONE" << endl;
    return 0;
}
