#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;

struct good{
    int w, v;
};

int n, m;
int f[N];

int main()
{
    cin >> n >> m;
    vector<good> Goods;

    //二进制处理
    for(int i = 1; i <= n; i ++)
    {
        int v, w, s;
        cin >> v >> w >> s;

        for(int k = 1; k <= s; k *= 2)
        {
            s -= k;
            Goods.push_back({k * w, k * v});
        }
        if(s > 0)
            Goods.push_back({s * w, s * v});
    }

    for(auto good = Goods.begin(); good != Goods.end(); good ++)
        //在迭代时候，good是一个容器，而元素是一个结构体
        //(*good).v 不能写为*good.v 因为（）的运算符优先级大于* 不带括号就为*(good.v)
        //推荐使用good->v 完全等价且简便
        for(int j = m; j >= good->v; j --)
        {
            f[j] = max(f[j], f[j - good->v] + good->w);
        }

    cout << f[m] << endl;
    return 0;
}