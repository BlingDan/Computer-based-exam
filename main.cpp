#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> bit;
int n, x, y;

int main()
{
    cin >> n >> x >> y;

    while(n) {
        int t = n % 2;
        n /= 2;
        bit.push_back(t);
    }

    for(int i = bit.size(); i <= 30; i ++) bit.push_back(0);
    swap(bit[x], bit[y]);
    int ans = 0;
    for(int i = bit.size() - 1; i >= 0; i --)
        ans = ans * 2 + bit[i];

    cout << ans << endl;
}