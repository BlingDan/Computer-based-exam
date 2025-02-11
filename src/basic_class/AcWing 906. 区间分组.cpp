#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
/**
 * 区间分组问题，可以使用贪心思路解决
 * 常常将左端点或者右端点进行排序然后处理
 * 小根堆的使用：priority_queue<int, vector<int>, greater<int>> vector<int>是底层容器，不用太过深究
 * 大根堆的使用就比较简单：priority_queue<int>
 */
const int N = 100010;
struct Range{
    int l;
    int r;
}ranges[N];

bool compareByLeft (const Range &a, const Range &b)
{
    return a.l < b.l;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> ranges[i].l >> ranges[i].r;
    sort(ranges, ranges + n, compareByLeft);

    //最小堆，存储每个组中最后一个区间的右端点
    priority_queue<int, vector<int>, greater<int>> heap;

    for(int i = 0; i < n; i ++)
    {
        int l = ranges[i].l;
        int r = ranges[i].r;

        if(!heap.empty() && heap.top() < l)
            heap.pop();

        heap.push(r);
    }

    cout << heap.size() << endl;
    return 0;

}
