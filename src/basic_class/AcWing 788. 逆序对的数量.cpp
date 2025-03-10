#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];
long long count;    // use long long to prevent overflow, as the maximum number of inversion can reach 1e10 in the worst case(e.g. n=1e5)

void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int i = l, j = mid + 1, tmp[r - l + 1];
    int k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]){
            tmp[k ++] = q[i ++];
        }
        else {
            tmp[k++] = q[j++];
            count += mid - i + 1;
        }
    }

    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];

    for(int i = l, k = 0; k < r - l + 1; i ++, k ++)
        q[i] = tmp[k];

    return;
}

int main()
{
    count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    cout << count << endl;
    return 0;
}