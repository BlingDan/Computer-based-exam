#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while(i < j)
    {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}


int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)  scanf("%d", &q[i]);
    quick_sort(q, 1, n);

    int mid = (1 + n) >> 1;
    int res = 0;
    for(int i = 1; i <= n; i ++)
        res += abs(q[mid] - q[i]);

    cout << res << endl;
    return 0;

}
