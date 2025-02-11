#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> add(vector<int> A, vector<int>B)
{
    //方便计算，A中保存较长的数
    if(A.size() < B.size()) return add(B, A);

    vector<int> ans;
    int carry = 0;
    for(int i = 0; i < B.size(); i ++)
    {
        int tmp = A[i] + B[i] + carry;
        carry = tmp / 10; //进位
        ans.push_back(tmp % 10);
    }

    for(int i = B.size(); i < A.size(); i ++)
    {
        int tmp = A[i] + carry;
        ans.push_back(tmp % 10);
        carry = tmp / 10;
    }

    if(carry == 1) ans.push_back(carry);

    return ans;
}
int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;

    for(int i = a.size() - 1; i >= 0;  i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0;  i--) B.push_back(b[i] - '0');

    vector<int> ans = add(A, B);
    for(int i = ans.size() - 1; i >= 0; i --)
        cout << ans[i];

    return 0;
}
