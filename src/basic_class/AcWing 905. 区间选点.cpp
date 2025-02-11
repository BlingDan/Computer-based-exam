#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
struct Range{
    int l, r; //左右端点
}range[N];

/**
 * 右端点升序排序，使用引用&减少拷贝，使用常量const避免修改
 * @param a
 * @param b
 * @return
 */
bool compareByRight(const Range&a, const Range &b)
{
    return a.r < b.r;
}

void solution()
{
    sort(range, range + n, compareByRight);
    int count = 0;
    int ed = -2e9;
    for(int i = 0; i < n; i ++)
    {
        //出现区间断点,即左端点大于ed
        if(range[i].l > ed){
            ed = range[i].r;
            count ++;
        }
    }

    cout << count ;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d%d", &range[i].l, &range[i].r);
    solution();
    return 0;
}