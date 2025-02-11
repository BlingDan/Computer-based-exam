/**
 * 2025年1月17日 一刷
 * 不理解为什么用贪心＋二分。尤其是tails数组的定义很考验经验
 * 一刷直接过了二刷再说
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    vector<int> tails; // tails[i] 表示长度为 i+1 的上升子序列的最小末尾元素
    for(int x: a)
    {
        auto it = lower_bound(tails.begin(), tails.end(), x); // 使用二分查找找到第一个 >= x 的位置
        if(it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }

    cout << tails.size() << endl;
    return 0;
}
