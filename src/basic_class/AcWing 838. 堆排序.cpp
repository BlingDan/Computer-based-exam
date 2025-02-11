#include <iostream>
#include <algorithm>

using  namespace std;

const int N = 100010;

int h[N], sizes;
int m;


void down(int u)
{
    // down操作的核心思想：看一下当前结点是不是三个结点（本身，左右结点）中的最小/大值
    int t = u; // 先记录
    if(2 * u <= sizes && h[t] > h[2 * u]) t = 2 * u;
    if(2 * u + 1 <= sizes && h[t] > h[2 * u + 1]) t = 2 * u + 1;

    if(t != u) {
        // 说明最小/大值不是当前根节点 而是在子节点上交换后继续down
        swap(h[t], h[u]);
        down(t);
    }
}

void init()
{
    //初始化堆，从size/1~1
    for(int i = sizes / 2; i >= 1; i --)
        down(i);
//
//    for(int i = 1; i <= sizes; i ++)
//        cout << h[i] << ' ';
//    cout << endl;
}

int main()
{
    cin >> sizes >> m;
    for(int i = 1; i <= sizes; i ++)
        scanf("%d", &h[i]);

    init();
    while(m --)
    {
        cout << h[1] << ' ';
        h[1] = h[sizes --];
        down(1);
    }

    return 0;
}
