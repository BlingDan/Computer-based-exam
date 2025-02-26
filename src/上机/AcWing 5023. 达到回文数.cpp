//
// Created by HUAWEI on 2025/2/11.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> num;
vector<int> rev;
bool check(int x)
{
    rev.clear();
    num.clear();
    while(x)
    {
        num.push_back(x % 10);
        x /= 10;
    }

    rev = num;
    reverse(num.begin(), num.end());
//    cout << "After reverse, num:" << endl;
//    for(auto item:num) cout << item << ' '; cout << endl;
    for(int i = 0; i <= num.size() / 2; i ++)
    {
        if(rev[i] + num[i] >= 10)
            return false;
        if(rev[i] != num[i])
            return false;
    }
    return true;


}
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while(!check(n))
    {
        int m = 0;
        for(int i = 0; i < num.size(); i ++)
            m = m * 10 + rev[i];

        if(n == m) break;
//        cout << n << ' ' << m << endl;
        n += m;
        cnt ++;
    }
    cout << cnt << ' ' << n << endl;
}
