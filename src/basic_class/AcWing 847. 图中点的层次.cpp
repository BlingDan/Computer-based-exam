#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int q[N];   //队列
int h[N], e[N], ne[N], idx; //别忘记初始化
int n, m;   //n条结点m条边
int d[N];   //存储每个结点到原点的距离 初始化为-1代表未连接

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int bfs()
{
    memset(d, -1 , sizeof d);

    //使用队列维护, 从结点1开始
    int hh = 0, tt = -1;
    d[1] = 0;   //初始化到自己距离为0
    q[++ tt] = 1;   //将结点放入队列

    //一直循环直到队列为空
    while(hh <= tt)
    {
        int t = q[hh ++];   //从队头取出元素
        for(int i = h[t]; i != -1; i = ne[i]) //从邻接表遍历相邻的点
        {
            int j = e[i]; //查看相邻点的结点编号
            if(d[j] == -1){ //如果没有遍历过
                d[j] = d[t] + 1; //更新
                q[++ tt] = j; //入队列
            }
        }
    }

    return d[n];

}

int main() {
    cin >> n >> m;
    int a, b;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }

//    for(int i = 1; i <= n; i ++)
//    {
//        cout << "head:" << i <<":";
//        for(int j = h[i]; j != -1; j = ne[j])
//        {
//            cout << "--" << e[j];
//        }
//        cout << endl;
//}
    int dist = bfs();
    cout << dist << endl;
    return 0;
}

