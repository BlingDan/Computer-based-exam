#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
struct Range {
    int l;
    int r;
}range[N];

bool compareByLeft(const Range& x1, const Range& x2)
{
    return x1.l < x2.l;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++)
        scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n, compareByLeft);

    int count = 1;
    int boundary = range[0].r;
    for(int i = 1; i < n; i ++) {
        if(range[i].l <= boundary)
            boundary = max(boundary, range[i].r);
        else {
            count ++;
            boundary = range[i].r;
        }
    }

    cout << count << endl;
    return 0;
}
