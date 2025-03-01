//
// Created by HUAWEI on 2025/3/1.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200;
struct Student{
    long long n;
    int g;

    bool operator < (const Student& t) {
        if(g != t.g)
            return g > t.g;
        else
            return n < t.n;
    }
}student[N];

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        cin >> student[i].n >> student[i].g;
        if(student[i].g >= 60)
            cnt ++;
    }

    sort(student, student + n);

    for(int i = 0; i < cnt; i ++)
        cout << student[i].n << ' ' << student[i].g << endl;

    return 0;
}
