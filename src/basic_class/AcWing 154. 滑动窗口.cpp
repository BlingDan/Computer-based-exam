#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n, k;
int a[N], q[N]; // q[N] 队列

void findMaxMinSlidingWindow()
{
    //最小值
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++)
    {
        // 最小值维护一个单调递增队列，至于为什么是单调递增队列，不是单调递减队列我也说不出所以然，
        // 就算说出了所以然也会忘记，所有我决定直接背答案，背会之后再思考为什么
        while(hh <= tt && a[q[tt]] >= a[i])
            tt --;
        q[++ tt] = i;

//        //说明滑动窗口满,输出队头并且队头后移一位 //这个是错误的
//        if(tt - hh > k)
//            cout << a[q[hh ++]] << ' ';

        // 移除不在窗口中的元素
        if(hh <= tt && q[hh] < i - k + 1)
            hh ++;

        //输出当前窗口的最小值, 当前遍历的元素下标为i（即窗口的结束位置，i-k+1是窗口的起始位置，
        //if中判断的是先行成窗口
        if(i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    cout << endl;
    //最大值
    hh = 0, tt = -1;
    for(int i = 0; i < n; i ++)
    {
        while(hh <= tt && a[q[tt]] <= a[i])
            tt --;
        q[++ tt] = i;

        if(hh <= tt && q[hh] < i - k + 1)
            hh ++;

        if(i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    cout << endl;
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    findMaxMinSlidingWindow();
    return 0;
}
