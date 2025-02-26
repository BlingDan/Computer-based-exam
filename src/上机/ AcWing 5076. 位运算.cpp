//
// Created by HUAWEI on 2025/2/11.
//
const int N = 1000010;
struct Data {
    int v, l;
    bool operator< (const Data &other)
    {
        if(l != other.l)
            return l > other.l;
        else
            v < other.v;
    }
}q[N];

int get_len(int x)
{
    if(x == 0) return -1;
    x = abs(x);

    int len = 0;
    while(x) len ++, x /= 10;
    return len;
}

int main()
{
    int n = 0;
    while(scanf("%d", &q[n].v) != -1)
    {
        q[n].l = get_len(q[n].v);
        n ++;
    }
    sort(q, q + n);
    for(int i = 0; i < n; i ++)
        cout << q[i].v << ' ';
    return 0;
}
