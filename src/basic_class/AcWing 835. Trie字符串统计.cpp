/**
* Tire树：高效存储，检索，前缀匹配字符串（多路哈夫曼树）
 * 思想：利用公共前缀减少存储空间并提高查找效率
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int idx = 0; //值得注意的是 若一个结点为0可能是头结点，也可能是空结点（没有用过的结点）
int son[N][26]; //任何结点都可能有26个字母的分支
int cnt[N]; //统计以当前结点结尾的字符串个数
char str[N];

void insert(char str[])
{
    int p = 0; // p = 0表示从头开始遍历tire树, p为下标
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a'; // 将a~z映射为0~25
        if(son[p][u] == 0)
            son[p][u] = ++ idx;
        p = son[p][u];
    }

    cnt[p] ++;
}

int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(son[p][u] == 0)
            return 0;

        p = son[p][u]; //第一次写忘记更新p下标 注意
    }

    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        char op[2];
        scanf("%s%s", op, str);
        if(op[0] == 'I')
            insert(str);
        else
            cout << query(str) << endl;
    }

    return 0;
}
