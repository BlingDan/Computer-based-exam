#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]);

    int i = n, j = m;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j]) {
            i --;
            j --;
        } else {
            j --;
        }
    }

    if(i == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
