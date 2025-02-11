#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];


void merge_sort(int q[], int l, int r)
{
    //termination condition for recursion
    if(l >= r) return;

    //step 1: devide into subproblem
    int mid = (l + r) >> 1;
    //step 2: recursively solve subproblem
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    //step 3: merge subproblem
    int i = l, j = mid + 1, tmp[r - l + 1];  //if use j = mid, it will cause array overlap!!!!
    int k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] < q[j]){
            tmp[k ++] = q[i ++];
        }
        else{
            tmp[k ++] = q[j ++];
        }
    }

    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];

    for(int i = l, k = 0; k < r - l + 1; i ++, k ++)
        q[i] = tmp[k];

    return;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for(int i = 0; i < n; i ++) cout << q[i] << ' ';
    return 0;
}