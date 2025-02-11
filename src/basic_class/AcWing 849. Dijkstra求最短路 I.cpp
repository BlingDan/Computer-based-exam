#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII; // 存储距离和节点编号

const int N = 100010;
int n, m;
int e[N], ne[N], h[N], w[N], idx;
bool st[N];
int dist[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);    //初始化所有点到原点距离为无穷
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;    //因为在寻早最短距离时候要遍历所有点，故用小根堆优化
    heap.push({0, 1});

    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();

        int distance = t.first;
        int ver = t.second;
        if(st[ver])
            continue;   //如果该点已经访问过则下一位
        else
            st[ver] = true;    //否则标记选出来的距离最短的点

        for(int i = h[ver]; i != -1; i = ne[i]) //遍历当前结点的所有邻接边
        {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;
    return 0;

}
