//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

float x1, x2, y1, y2;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    x1 = (float)(a + c) / 2;
    y1 = (float)(b + d) / 2;
    cin >> a >> b >> c >> d;
    x2 = (float)(a + c) / 2;
    y2 = (float)(b + d) / 2;

    float k = (y1 - y2) / (x1 - x2);
    float b1 = y2 -(k * x2) ;
    printf("%.8f\n%.8f\n", k, b1);

}
