#include <iostream>
#include <algorithm>

using namespace std;
/**
 * 贪心算法区间调度问题：
 * 1.起点排序：每次选择起点最小的区间，导致压缩了后续空间的可选性，导致最终选择的区间少
 * 2.终点排序：每次选择终点最小的区间，能够为后续区间留下更大空间，保证最终选择的区间最多
 */
const int N = 100010;
int n;
struct Range{
    int l, r;
}range[N];

bool compareByRight(const Range &a, const Range &b)
{
    return a.r < b.r;
}

void solution()
{
    sort(range, range + n, compareByRight);
    int count = 0;
    int ed = -2e9;
    for(int i = 0; i < n; i ++)
    {
        if(range[i].l > ed){
            ed = range[i].r;
            count ++;
        }

    }

    cout << count << endl;
    return;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n;i ++) scanf("%d%d", &range[i].l, &range[i].r);
    solution();
    return 0;
}