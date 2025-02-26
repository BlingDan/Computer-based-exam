//
// Created by HUAWEI on 2025/2/26.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mp {
        {"AX", 1}, {"BX", 2}, {"CX", 3}, {"DX", 4}
};

int reg[5];
int n;
string str;


int main()
{
    string tmp;
    while(cin >> str)
    {
        cin >> tmp;
        if(str == "OUT") {
            cout << reg[mp[tmp]] << endl;
            continue;
        }
        string pre = tmp.substr(0, tmp.find(','));
        string last = tmp.substr(tmp.find(',') + 1, -1);

        int cur = mp[pre];
        if(str == "IN") {
            int num = stoi(last);
            reg[cur] = num;
        } else if(str == "MOV") {
            reg[cur] = reg[mp[last]];
        } else if(str == "ADD") {
            reg[cur]  += reg[mp[last]];
        } else if(str == "SUB") {
            reg[cur]  -= reg[mp[last]];
        } else if(str == "MUL") {
            reg[cur]  *= reg[mp[last]];
        } else if(str == "DIV") {
            reg[cur]  /= reg[mp[last]];
        }
    }

}
