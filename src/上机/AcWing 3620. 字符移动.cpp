//
// Created by HUAWEI on 2025/3/1.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;
char a[N];
int n;

bool is_num(char t)
{
    return (t >= '0' && t <= '9') ? true : false;
}

int main()
{
    string str;
    cin >> str;
    n = str.size();

    for(int i = 0; i < n; i ++)
        a[i] = str[i];

    for(int i = n - 1; i >= 0; i --)
    {
        if(is_num(a[i]))
        {
            int j = i + 1;
            while(j <= n - 1 && !is_num(a[j])) {
//                cout << a[j] << ' ' <<  a[j - 1] << endl;
                swap(a[j], a[j - 1]);
                j ++;
            }
        }
    }

    for(int i = 0; i < n; i ++)
        cout << a[i];

    return 0;
}
