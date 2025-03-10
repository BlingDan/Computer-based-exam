//
// Created by HUAWEI on 2025/3/9.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int f[N];   // f[i] 以a[i]结尾的最大子数组的和
int a[N];
int n;

int main()
{
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        int t;
        cin >> t;
        if(t == 1) {
            a[i] = -1;
            ans ++;
        } else
            a[i] = 1;
    }

    // 错误版本
//    f[1] = a[1];
//    for(int i = 2; i <= n; i ++)
//        f[i] = max(a[i], f[i - 1] + a[i]);
//
//    int tmp = 0;
//    for(int i = 1; i <= n; i ++)
//        tmp = max(tmp, f[i]);
//    cout << ans + tmp << endl;

//  正确：Kadane 算法 空间复杂度O(1)
//    int cur_max = -0x3f3f3f3f;
//    int max_inc = -1;
//    for(int i = 0; i < n; i ++)
//    {
//        cur_max = max(a[i], cur_max + a[i]);
//        max_inc = max(max_inc, cur_max);
//    }
//
//    cout << ans + max_inc << endl;

// 正确 空间复杂度O(n)
    f[0] = a[0];
    int tmp_max = f[0];
    for(int i = 1; i < n; i ++) {
        f[i] = max(a[i], f[i - 1] + a[i]);
        tmp_max = max(tmp_max, f[i]);
    }
    cout << tmp_max + ans << endl;
    return 0;
}
