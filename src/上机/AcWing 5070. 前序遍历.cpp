//
// Created by HUAWEI on 2025/2/15.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long LL;
const int N = 50010;
int a[N], b[N]; // a[n]存储后序遍历序列，b[n]存储中序遍历序列
unordered_map<int, int> p;
int ans;

void build(int al, int ar, int bl, int br)
{
    if(al > ar) return;

    int root = a[ar];
    int k = p[root];
    ans = root;
    build(al, k - 1 - bl + al, bl, k - 1);
    build(k - bl + al, ar - 1, k + 1, br);

}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &b[i]);
        p[b[i]] = i;
    }

    build(0, n - 1, 0, n - 1);
    cout << ans << endl;
    return 0;

}
