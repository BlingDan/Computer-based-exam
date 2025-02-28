//
// Created by HUAWEI on 2025/2/27.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

int get_dig(LL x)
{
    int ans = 0;
    while(x){
        ans ++;
        x /= 10;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    while(n --)
    {
        LL a, b;
        cin >> a >> b;
        cout << get_dig(a + b) << endl;
    }

    return 0;
}