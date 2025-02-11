#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], b[N];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]);

    int i = 1, j = m;
    while(i <= n && j >= 1)
    {
        if(a[i] + b[j] == x) {
            cout << i - 1 << ' ' << j - 1 << endl;
            break;
        }
        else if(a[i] + b[j] > x)
            j --;
        else
            i ++;
    }
    return 0;

}
