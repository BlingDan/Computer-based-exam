//
// Created by HUAWEI on 2025/3/1.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;

struct Student{
    long long num;
    string name;
    int a, b, c;

    bool operator <(const Student& other){
        if(a + b + c != other.a + other.b + other.c)
            return a + b + c > other.a + other.b + other.c;
        else
            return num < other.num;
    }
};

int main()
{
    int T;
    cin >> T;

    for(int m = 0; m < T; m ++)
    {
        Student student[N];
        int n;
        cin >> n;

        for(int i = 0; i < n; i ++)
        {
            auto t = &student[i];
            cin >> t->num >> t->name >> t->a >> t->b >> t->c;
        }

        sort(student, student + n);

        printf("case #%d:\n", m);
        for(int i = 0; i < n; i ++)
        {
            auto t = student[i];
            cout << t.num << ' ' << t.name << ' ' << t.a << ' ' << t.b << ' ' << t.c << endl;
        }
    }

    return 0;
}
