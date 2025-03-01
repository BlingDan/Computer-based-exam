#include <iostream>
#include <algorithm>

using namespace std;
/**
 * Tire数据结构，参考Acwing 835
 */
const int  N = 100010, M = 31 * N;

int son[M][2];
int idx;
int a[N];

void insert(int x)
{
    int p = 0;
    for(int i = 30; i >= 0; i --)
    {
        int u = x >> i & 1;
        if(son[p][u] == 0) son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0;
    int res = 0;
    for(int i = 30; i >= 0; i --)
    {
        int u = x >> i & 1;
        if(son[p][!u])
        {
            p = son[p][!u]; //从高位到低位保证异或最大
            res = res * 2 + !u;
        }
        else
        {
            p = son[p][u]; //没有异或为1只能凑合着用
            res = res * 2 + u;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        insert(a[i]);
        int t = query(a[i]);
        res = max(res, a[i] ^ t);
    }

    cout << res << endl;
    return 0;
}
