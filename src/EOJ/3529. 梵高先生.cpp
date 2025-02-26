//
// Created by HUAWEI on 2025/2/24.
//
#include <iostream>
using namespace std;

const int N = 25;
int f[N][N];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        f[i][1] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= i; j++) {
            f[i][j] = f[i-1][j] + f[i-1][j-1];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << f[i][j];
            if(j < i) cout << " ";  // 不是最后一个数后面加空格
        }
        cout << endl;
    }

    return 0;
}
