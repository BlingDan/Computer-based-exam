#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/**
 * 2025年1月24日
 * 没搞明白，一刷放弃
 */
const int N = 100010;
int h[N], sizes;
int ph[N], hp[N];   //pointer to heap / heap to pointer 分别记录，很奇怪的数组，互为反函数

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if(2 * u <= sizes && h[2 * u] < h[t]) t = 2 * u;
    if(2 * u + 1 <= sizes && h[2 * u + 1] < h[t]) t = 2 * u + 1;

    if(t != u) {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u)
{
    while(u / 2 && h[u / 2] > h[u]) {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main()
{
    int n, m = 0;
    cin >> n;
    while(n --)
    {
        char op[5];
        int k, x;
        scanf("%s", op);

        if(!strcmp(op, "I"))
        {
            scanf("%d", &x);
            sizes ++;
            m ++;
            ph[m] = sizes, hp[sizes] = m;
            h[sizes] = m;
            up（sizes);
        }

    }
}
