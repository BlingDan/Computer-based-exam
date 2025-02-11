// 高精度除法
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 *
 * @param A 从低位到高位
 * @param B 除数 1<= b <=10000
 * @param r 余数，传递的为引用
 * @return  商
 */
vector<int> div (vector<int> A, int b , int & r)
{
    vector<int> C;
    r = 0;

    //除法运算从高位开始计算
    for(int i = A.size() - 1; i >= 0; i --)
    {
        int tmp = A[i] + r * 10;
        C.push_back(tmp / b);
        r = tmp % b;
    }

    reverse(C.begin(), C.end());
    //去除前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main()
{
    string str1;
    cin >> str1;
    int b, r;
    cin >> b;
    vector<int> A;
    for(int i = str1.size() - 1; i >= 0; i --) A.push_back(str1[i] - '0');

    vector<int> C = div(A, b, r);
    for(int i = C.size() - 1; i >= 0; i --)
        cout << C[i];
    cout << endl << r << endl;

    return 0;
}
