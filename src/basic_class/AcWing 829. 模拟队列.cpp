#include <iostream>

using namespace std;

const int N = 100010;

int head = 0;
int rear = -1;
int q[N];

void push(int x)
{
    q[++ rear] = x;
}
void pop()
{
    head ++;
}
void empty()
{
    if(rear < head)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void query()
{
    cout << q[head] << endl;
}
int main()
{
    int m;
    cin >> m;
    while(m --)
    {
        string op;
        cin >> op;
        if(op == "push"){
            int x; cin >> x;
            push(x);
        }else if(op == "pop") {
            pop();
        }else if(op == "empty") {
            empty();
        }else{
            query();
        }
    }
    return 0;
}
