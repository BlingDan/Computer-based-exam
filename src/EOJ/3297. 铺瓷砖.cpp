//
// Created by HUAWEI on 2025/3/8.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int count_1;
int count_solution;

// x: 当前的数  res:累加的和  k: 1的数量
void dfs(int x, int res, int k)
{
    res += x;
    if(x == 1) k ++;

    if(res > n) return;
    if(res == n) {
        count_solution++;
        count_1 += k;
        return;
    }

    for(int i = 1; i <= 3; i ++)
    {
        if(x == i) continue;
        dfs(i, res, k);
    }

}


int main()
{
    int T;
    cin >> T;

    while(T --)
    {
        count_1 = 0;
        count_solution = 0;
        cin >> n;
        for(int i = 1; i <= 3; i ++)
            dfs(i, 0, 0);

        cout << count_solution << "\n" << count_1 << "\n";
    }
}
