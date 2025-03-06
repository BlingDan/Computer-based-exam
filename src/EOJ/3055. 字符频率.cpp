//
// Created by HUAWEI on 2025/3/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
char str[N];
double freq[26];

char low_ch(char x)
{
    if(x >= 'a' && x <= 'z')
        return x;
    else
        return x - 'A' + 'a';
}

bool cmp(const char &ch1, const char &ch2)
{
    if(low_ch(ch1) == low_ch(ch2))
        return ch1 > ch2;
    int lch1 = low_ch(ch1) - 'a';
    int lch2 = low_ch(ch2) - 'a';
    return freq[lch1] < freq[lch2] ? 0 : 1;
}

int main()
{
    int T;
    cin >> T;

    for(int count = 0; count < T; count ++)
    {
        memset(freq, 0, sizeof freq);

        for(int i = 0; i < 26; i ++)
            cin >> freq[i];

        string tmp;
        cin >> tmp;
        int n = tmp.size();
        for(int i = 0; i < n; i ++)
            str[i] = tmp[i];
        sort(str, str + n, cmp);

        printf("case #%d:\n", count);
        for(int i = 0; i < n; i ++)
            cout << str[i];
        cout << endl;
    }
}
