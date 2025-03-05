//
// Created by HUAWEI on 2025/3/3.
//
#include <iostream>

using namespace std;

int main() {
    unsigned int m; // m 仍然可以是 unsigned int
    int p, n;

    cin >> m >> p >> n;

    for (int i = 0; i < n; ++i) {
        int current_bit = p - i;

        int t = m >> current_bit & 1;
        if(t == 1)
            m -= 1 << current_bit;
        else
            m += 1 << current_bit;
    }

    cout << m << endl;

    return 0;
}
