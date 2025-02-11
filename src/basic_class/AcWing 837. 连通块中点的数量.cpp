#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];   //结点k的祖宗结点
int sizes[N];    //当前结点所处的连通块大小

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void init()
{
    for(int i = 1; i <= n; i ++)
    {
        p[i] = i;   //初始化结点祖先为其本身
        sizes[i] = 1;    //连通块大小为1
    }
}

int main()
{
    cin >> n >> m;
    char op[5];
    int a, b;

    init();
    for(int i = 0; i < m; i ++)
    {
        scanf("%s", op);
        if(op[0] == 'C'){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)){
                continue; //a, b 在同一个连通块中不做处理
            }

            sizes[find(b)] += sizes[find(a)];
            p[find(a)] = find(b);   //a结点的祖宗结点连接到B的祖宗结点
        }else if(op[1] == '1'){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }else {
            scanf("%d", &a);
            cout << sizes[find(a)] << endl;
        }
    }

    return 0;
}