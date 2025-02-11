// 高精度乘法
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mul (vector<int> A, vector<int> B)
{
    vector<int> C(A.size() + B.size(), 0);

    // i + j 位数的值相乘后相加
    for(int i = 0; i < A.size(); i ++)
        for(int j = 0; j < B.size(); j ++)
        {
            C[i + j] += A[i] * B[j];
        }

    //处理进位
    int carry = 0;
    for(int i = 0; i < C.size(); i ++)
    {
        int tmp = C[i] + carry;
        carry = tmp / 10;
        C[i]  = tmp % 10;
    }

    //处理前置0
    while(C.size() >= 2 && C.back() == 0) C.pop_back();
    reverse(C.begin(), C.end());
    return C;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> A, B;
    for(int i = str1.size() - 1; i >= 0; i --) A.push_back(str1[i] - '0');
    for(int i = str2.size() - 1; i >= 0; i --) B.push_back(str2[i] - '0');

    vector<int> ans = mul(A, B);
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i];

    return 0;
}
