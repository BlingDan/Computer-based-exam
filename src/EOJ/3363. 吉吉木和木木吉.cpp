//
// Created by HUAWEI on 2025/3/9.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[6], b[6];
int main()
{
    for(int i = 0; i < 6; i ++) cin >> a[i];
    for(int i = 0; i < 6; i ++) cin >> b[i];

    int fenzi = 0;
    int fenmu = 0;
    for(int i = 0; i < 6; i ++)
        for(int j = 0; j < 6; j ++)
        {
            if(a[i] != b[j]) fenmu ++;
            if(a[i] > b[j]) fenzi ++;
        }

    float ans = (float) fenzi / fenmu;
    printf("%.5f", ans);
    return 0;
}
