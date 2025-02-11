#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N];

/**
 * 从暴力解法入手 i: 0 ~ n - 1, j: 0 ~ i, k：j ~ i 这样时间复杂度为n^3
 * 减少重复检查：j ~ i 中是否有重复数字可以使用哈希表 hash / unordered_map快速判断
 * 避免不必要的枚举：如果 j ~ i 中有重复元素，那么j ~i + 1中一定有重复元素，j 直接后移即可
 *
 */
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    int res = 0;
    int j = 0;
    for(int i = 0; i < n; i ++)
    {
        s[a[i]] ++;
        while(s[a[i]] > 1) {
            s[a[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }

    cout << res << endl;
    return 0;
}
