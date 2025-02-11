#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010;
int st[N];
/**
 * 第一次写的时候top设置为0，后面的代码写的很乱，还是-1好
 */
int main()
{
    int n;
    cin >> n;
    int top = -1;
    while(n --)
    {
        int x;
        cin >> x;
        //若当前元素小于等于栈顶元素，栈顶元素出栈
        while(top != -1 && st[top] >= x)
            top --;
        //若栈为空，输出-1
        if(top == -1){
            st[++ top] = x;
            cout << -1 << ' ';
        }
        else {
            cout << st[top] << ' ';
            st[++ top] = x;
        }
    }
    return 0;
}
