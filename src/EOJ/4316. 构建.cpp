//
// Created by HUAWEI on 2025/3/3.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int main()
{
    int t;
    for(int i = 0; i < 4; i ++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
//    for(auto it:v) cout << it << ' ';
//    cout << endl;
    int res = 0;

    if(v[0] + v[1] + v[2] > v[3])
        cout << "quadrangle" << endl;
    else if(v[0] + v[1] > v[2] || v[1] + v[2] > v[3]) {
        cout << "triangle" << endl;
    }else
        cout << "Impossible" << endl;

    return 0;
}
