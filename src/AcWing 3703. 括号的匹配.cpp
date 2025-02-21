//
// Created by HUAWEI on 2025/2/20.
//
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
    unordered_map<char, int> priority = {{'{', 1}, {'[', 2}, {'(', 3}, {'<', 4}};

    while (n--) {
        string s;
        cin >> s;
        stack<char> st;
        int p = 0; // 当前栈的最大优先级

        bool valid = true;
        for (char c : s) {
            if (priority.count(c)) { // 左括号
                st.push(c);
                p = max(p, priority[c]);
            } else { // 右括号
                if (st.empty() || st.top() != match[c]) {
                    valid = false;
                    break;
                }
                if (priority[st.top()] < p) {
                    valid = false;
                    break;
                }
                st.pop();
                p = 0; // 更新 p
                stack<char> temp = st;
                while (!temp.empty()) {
                    p = max(p, priority[temp.top()]);
                    temp.pop();
                }
            }
        }
        if (!st.empty()) valid = false;
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}
