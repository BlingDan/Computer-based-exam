#include <iostream>

using namespace std;

const int N = 1e6 + 10;
// reference :https://blog.csdn.net/m0_74215326/article/details/128770930
int head, idx;
int n[N], ne[N];

void init()
{
    head = -1;
    idx = 0;
}
void add_to_head(int x)
{
    n[idx] = x;
    ne[idx] = head;
    head = idx ++;
}

void delete_k(int k)
{
    //当k为头结点时候注意！！
    if (k == -1) head = ne[head];
    else
        ne[k] = ne[ne[k]];
}

void insert_after_k(int k, int x)
{
    n[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}

int main()
{
    init();

    int m;
    cin >> m;
    char op;
    while(m --)
    {
        cin >> op;
        if(op == 'H')
        {
            int x;
            cin >> x;
            add_to_head(x);
        }
        if(op == 'D')
        {
            int k;
            cin >> k;
            delete_k(k - 1);
        }
        if(op == 'I')
        {
            int k, x;
            cin >> k >> x;
            insert_after_k(k - 1,x);
        }
    }

    for(int i = head; i != -1; i = ne[i]) cout << n[i] << ' ' ;
    return 0;

}
