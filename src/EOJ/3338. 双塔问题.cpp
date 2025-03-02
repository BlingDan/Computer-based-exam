//
// Created by HUAWEI on 2025/3/2.
//
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 110, M = 10010;
//int f[N][M];
//int a[N];
//int n, m;
//
//int main()
//{
//    cin >> n;
//    for(int i = 1; i <= n; i ++){
//        cin >> a[i];
//        m += a[i];
//    }
//
//    //  f[i][j] 为前 i 块积木中，两座塔高度差为 j 时，较高的那座塔的最大高度
//    for(int i = 1; i <= n; i ++)
//        for(int j = 0; j <= m; j ++)
//        {
//            // 不选择
//            f[i][j] = f[i - 1][j];
//
//            // 将第i块分配给较矮的塔
//            if(j >= a[i])
//                f[i][j] = max(f[i][j], f[i - 1][j + a[i]]);
//            else
//                f[i][j] = max(f[i][j], f[i - 1][a[i] - j] + j);
//
//            // 将第i块分配给较高的塔
//            f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + a[i]);
//        }
//
//    cout << f[n][0] << endl;
//
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;
int f[N][M];
int a[N];
int n, m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m += a[i];
    }

    // 初始化
    memset(f, -0x3f, sizeof(f)); // 初始化为负无穷
    f[0][0] = 0;

    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // 不选择
            f[i][j] = f[i - 1][j];

            // 将第i块分配给较矮的塔
            if (j >= a[i])
                f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + a[i]);
            else
                f[i][j] = max(f[i][j], f[i - 1][a[i] - j] + j);

            // 将第i块分配给较高的塔
            f[i][j] = max(f[i][j], f[i - 1][j + a[i]]);
        }
    }

    if(f[n][0] <= 0) cout << 0 << endl;
    else cout << f[n][0] << endl;

    return 0;
}
