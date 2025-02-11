#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

queue<string> q; //队列，存储状态
unordered_map<string, int> d; //记录已经访问过的状态

int bfs(string start)
{
    string end = "12345678x";
    q.push(start);
    int distance = 0;
    d[start] = 0;

    int dx[] = {0, 0 ,-1, 1};
    int dy[] = {1, -1, 0, 0};
    while(q.size())
    {
        string tmp = q.front();
        if(tmp == end) return d[tmp]; //等于最终状态

        int index = tmp.find('x');    //取出队头元素并找到x下标
        q.pop();

        int x = index / 3, y = index % 3;
        // 状态转移
        for(int i = 0; i < 4; i ++)
        {
            int distance = d[tmp];
            int a = x + dx[i], b = y + dy[i];
            if(a < 3 && a >= 0 && b < 3 && b >= 0)
            {
                swap(tmp[index], tmp[a * 3 + b]);

                //如果新的状态是第一次遍历，哈希表中则没有记录使用count()结果为0
                if(!d.count(tmp))
                {
                    q.push(tmp);    //新状态压入队列
                    d[tmp] = distance + 1;
                }

                //还原状态为下一次状态做准备，注意现在还是在遍历上下左右
                swap(tmp[index], tmp[a * 3 + b]);
            }
        }
    }

    return -1;
}

int main()
{
    string start;
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
        {
            char c;
            cin >> c;
            start += c;
        }

    int ans = bfs(start);
    cout << ans << endl;
    return 0;
}