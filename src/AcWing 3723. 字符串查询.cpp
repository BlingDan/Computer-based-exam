//
// Created by HUAWEI on 2025/2/10.
//
/**
 * 注意要先用之前一列更新当且列再加
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010, M = 30;
int s[N][M];   // s[i][j] 前i个单词中，字母j出现的次数
string str;

bool check(int a, int b, int c, int d)
{
    // 对比每个字母出现的次数
    for(int i = 1; i <= 26; i ++)
    {
        int cnt1 = s[b][i] - s[a - 1][i];
        int cnt2 = s[d][i] - s[c - 1][i];
        if(cnt1 != cnt2)
        {
//            char t = i - 1 + 'a';
//            cout <<"NUM:" << t  << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> str;
    for(int i = 0; i < str.size(); i ++)
    {
        int num = str[i] - 'a' + 1;
        for(int j = 1; j <= 26; j ++)
            s[i + 1][j] = s[i][j];
        s[i + 1][num] ++;
    }

    int Q;
    cin >> Q;
    while(Q --)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(check(a, b, c, d))
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
    return 0;
}
