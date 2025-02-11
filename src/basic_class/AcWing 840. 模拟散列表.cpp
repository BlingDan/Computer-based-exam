#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 3;  // 开大一点减少冲突
int h[N]; // 开放寻址创建哈希表
int null = 0x3f3f3f3f;

void insert(int x)
{
    int t = (x % N + N) % N;
    while(h[t] != null && h[t] != x) {
        t ++;
        if(t == N)
            t = 0;
    }
    h[t] = x;
}

int query(int x)
{
    int t = (x % N + N) % N;
    while(h[t] != x){
        t = (t + 1) % N;
        if(h[t] == null)
            return -1;
    }
    return t;
}

int main()
{
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof h);
    while(n --)
    {
        char op[2];
        int x;
        scanf("%s%d", &op, &x);
        if(op[0] == 'I')
            insert(x);
        else {
            if(query(x) == -1)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }

    return 0;
}
