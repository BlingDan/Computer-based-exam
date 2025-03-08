//
// Created by HUAWEI on 2025/3/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int get_dig(int x)
{
    int ans = 0;
    while(x){
        ans ++;
        x /= 2;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int q = 0; q < T; q ++)
    {
        int n;
        cin >> n;

        int ans = 1;
        int tmp = 1;
        int count = get_dig(n);
//        cout << count << endl;
        for(int i = 0; i < count; i ++)
        {
            if(n == 0)
                break;

            if(((n >> i & 1) ^ (n >> (i + 1) & 1)) && i + 1 < count) {
//                cout << "i:" << i << endl;
                tmp ++;
                ans = max(ans, tmp);
            } else {
                ans = max(ans, tmp);
                tmp = 1;
            }
        }

        printf("case #%d:\n", q);
        cout << ans << endl;
    }

}
