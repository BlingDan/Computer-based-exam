#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range{
    int l;
    int r;
}ranges[N];

bool compareByLeft(const Range&a, const Range&b)
{
    return a.l < b.l;
}


int main()
{
    int s, t, n;
    cin >> s >> t >> n;
    for(int i = 0; i < n; i ++)
        cin >> ranges[i].l >> ranges[i].r;

    sort(ranges, ranges + n, compareByLeft);

    int ans = 0;
    bool success = false;
    for(int i = 0; i < n; i ++)
    {
        //寻找左端点<=s 且 右端点最大的区间
        int j = i;
        int MaxR = -2e9;
        while(j <= n && ranges[j].l <= s){
            MaxR = max(MaxR, ranges[j].r);
            j ++;
        }

        //若所有的右端点都小于s，说明没有可覆盖的点
        if(MaxR < s) break;

        ans ++;
        s = MaxR; //更新当前起点
        if(s >= t)
        {
            success = true;
            break;
        }
    }
    if(success) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}