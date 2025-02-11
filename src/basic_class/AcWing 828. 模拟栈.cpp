#include <iostream>

using namespace std;

const int N = 100010;
int st[N];

int main()
{
    int m;
    cin >> m;
    int top = -1;
    while(m --)
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            int x;
            cin >> x;
            st[++top] = x;
        }
        if(op == "pop")
        {
            st[top --];
//            int num = st[top --];
//            cout << num << endl;
        }
        if(op == "empty")
        {
            if(top == -1) cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        if(op == "query")
        {
            cout << st[top] << endl;
        }
    }
}