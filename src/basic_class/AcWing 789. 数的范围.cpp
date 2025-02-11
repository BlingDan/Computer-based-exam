#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 脑子痛不想写了，https://www.acwing.com/video/231/剩下自己看吧，没测试
 */
const int N = 100010;
int arr[N];

void bsearch_1(int q[],int l, int  r)
{

    while(l < r)
    {
        int x;
        cin >> x;
        int mid = (l + r) >> 1;
        if(q[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

void bsearch_2(int q[], int l, int  r)
{
    while(l < r)
    {
        int x;
        cin >> x;
        int mid = (l + r + 1) >> 1;
        if(q[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    while(m --)
    {
        int k;
        cin >> k;

    }
}