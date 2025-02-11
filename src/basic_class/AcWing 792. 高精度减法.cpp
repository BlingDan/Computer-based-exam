#include <iostream>
#include <vector>
/**
 * 不想写了
 */
using namespace std;

void sub(vector<int> A, vector<int> B, vector<int> &ans)
{
    //若A位数少，用B-A返回 false代表负数
    if(A.size() < B.size()) return sub(B, A, ans);
    if(A.size() == B.size()) {
        for(int i = A.size() - 1; i >= 0; i ++){
            if(A[i] >= B[i])
                continue;
            else
                return sub(B, A, ans);
        }
    }


}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> A, B;
    for(int i = str1.size() - 1; i >= 0; i --) A.push_back(str1[i] - '0');
    for(int i = str2.size() - 1; i >= 0; i --) A.push_back(str2[i] - '0');


}
