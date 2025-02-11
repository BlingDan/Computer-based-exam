#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

//并查集中寻找祖宗结点并且压缩路径，小巧但十分精炼
int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    //初始化，结点i的祖宗结点为其本身
    for(int i = 1; i <= n; i ++) p[i] = i;

    for(int i = 0; i < m; i ++)
    {
        int a, b;
        char op[2];
        scanf("%s%d%d", &op, &a, &b);
        if(op[0] == 'M') {
            p[find(a)] = find(b); //将a的祖宗结点连接到b的祖宗结点
        }else {
            if(find(a) == find(b)) cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
