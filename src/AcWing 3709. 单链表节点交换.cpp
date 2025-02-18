//
// Created by HUAWEI on 2025/2/18.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    for(int i = 0; i + 1 < n; i += 2)
        swap(a[i], a[i + 1]);
    for(int i = 0; i < n; i ++)
        cout << a[i] << ' ';
    return 0;
}
