//
// Created by HUAWEI on 2025/3/4.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, v;

int main()
{
    cin >> n >> v;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

//    for(int i = 1; i <= n; i ++)    cout << a[i] << ' ';
//    cout << endl;
    int ans = 0;
    int l = 1, r = n;
    while(l < r)
    {
        if(a[l] + a[r] > v) {
            ans ++;
            r --;
        } else {
            ans ++;
            l ++;
            r --;
        }
    }
    if(l == r) ans ++;
    cout << ans << endl;
}
