//
// Created by HUAWEI on 2025/2/14.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int N = 100010;
int n, k;
int a[N], arr[N];
int q[N];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    while(k --)
    {
        for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);
        int hh = 0, tt = -1;
        int idx = 0; // 删除队列序列指针

        for(int i = 0; i < n; i ++)
        {
            q[++ tt] = a[i];
            while(hh <= tt)
            {
                if(q[hh] == arr[idx])
                    hh ++, idx ++;
                else if(q[tt] == arr[idx])
                    tt --, idx ++;
                else
                    break;
            }
        }
        if(idx == n) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
