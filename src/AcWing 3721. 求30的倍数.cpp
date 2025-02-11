//
// Created by HUAWEI on 2025/2/10.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10;
vector<int> a;


int solution()
{
    // 30的倍数能被3和10整除
    sort(a.begin(), a.end(), greater<int>());

//    for(auto item : a) cout << item << ' ';
//    cout << endl;
    // 末尾没有0一定不能被10整除
    if(a.back()!= 0) return -1;
    // 每位的和不是3的倍数
    int sum = 0, ans = 0;
    for(auto item : a){
        sum += item;
        ans = ans * 10 + item;
    }
    if(sum % 3 != 0)
        return -1;
    else
        return ans;

}

int main()
{
    int n;
    cin >> n;
    while(n) {
        a.push_back(n % 10);
        n /= 10;
    }

    int ans = solution();
    cout << ans << endl;
    return 0;

}
