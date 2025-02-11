#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
/**
 * 模板题，多看多背就OK
 * 注意unordered_map：
 *  键值对存储：每个元素是一个 pair<const Key, Value>，其中 Key 是键，Value 是值。
    哈希表实现：通过哈希函数将键映射到桶（bucket）中，支持快速查找。
    无序性：元素存储顺序与插入顺序无关，取决于哈希函数和桶的分布。
    唯一键：每个键在 unordered_map 中只能出现一次（键是唯一的）。
    {{}, {}, {}}
 */

using namespace std;

stack<int> num;
stack<char> op;

void eval()
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();

    char c = op.top();
    op.pop();
    int ans = 0;
    if(c == '+') ans = a + b;
    if(c == '-') ans = a - b;
    if(c == '*') ans = a * b;
    if(c == '/') ans = a / b;

    num.push(ans);
}
int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2},{'/', 2}, {'^', 3}};
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i ++)
    {
        char c = str[i];
        if(isdigit(c)){
            int x = 0, j = i;
            while(j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j ++] - '0';

            i = j - 1;
            num.push(x);
        }
        else if(c == '('){
            op.push(c);
        }else if(c == ')'){
            while(op.top() != '(')
                eval();
            op.pop();
        }else{
            while(op.size() && pr[op.top()] >= pr[c]){
                eval();
            }
            op.push(c);
        }
    }
    while(op.size()) eval();
    cout << num.top() << endl;
    return 0;
}
