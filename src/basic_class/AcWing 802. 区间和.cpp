#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 10;
int n, m;
int a[N];
int s[N];   //前缀和数组
vector<int> alls;   // 存储所有插入和查询的操作
vector<pair<int, int>> add ,query;


// 二分查找离散化后的坐标
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;   // 下标从1开始
}


int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int i = 0; i < m; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 离散化：排序+去重
    sort(alls.begin(), alls.end());
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

    // 处理插入
    for(auto item : add) {
        int idx = find(item.first);
        a[idx] += item.second;
    }

    // 前缀和
    for(int i = 1; i <= alls.size(); i ++) {
        s[i] += s[i - 1] + a[i];
    }

    // 处理查询
    for(auto item : query) {
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
