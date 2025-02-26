//
// Created by HUAWEI on 2025/2/26.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, int> PII;     // first:距离，second:节点编号

const int N = 110, M = 10010;

unordered_map<string, int> mp;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dijkstra(int x, int y)
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;        //小根堆
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    heap.push({0, x});

    while(!heap.empty())
    {
        auto t = heap.top();
        heap.pop();

        int distance = t.first;
        int ver = t.second;
        if(st[ver])
            continue;
        else
            st[ver] = true;

        // 遍历选出点的所有邻接边
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if(dist[y] == 0x3f3f3f3f) return -1;
    return dist[y];
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < m; i ++)
    {
        string s1, s2;
        int c;
        cin >> s1 >> s2 >> c;
        if(mp.count(s1) == 0)   mp.insert({s1, cnt ++});
        if(mp.count(s2) == 0)   mp.insert({s2, cnt ++});
        int a = mp[s1], b = mp[s2];
        add(a, b, c);
        add(b, a, c);
    }

    int t;
    cin >> t;
    while(t --)
    {
        memset(st, 0, sizeof st);
        string s1, s2;
        cin >> s1 >> s2;
        if(mp.count(s1) == 0 || mp.count(s2) == 0) {
            cout << -1 << endl;
        }else {
            int x = mp[s1], y = mp[s2];
            cout << dijkstra(x, y) << endl;
        }
    }

    return 0;
}
