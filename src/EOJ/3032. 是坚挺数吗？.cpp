//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 10010;

int is_firm(int num, int div)
{
    if(num < div)
        return num;
    else if(num % div == 0)
        return 0;
    else
        return is_firm(num - num / div, div + 1);

}
int main()
{
    int T;
    cin >> T;

    for(int q = 0; q < T; q ++)
    {
        int n;
        cin >> n;

        printf("case #%d:\n", q);
        int pos = is_firm(n, 2);
        if(pos)
            cout << "Yes " << pos << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}