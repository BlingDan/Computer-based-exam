#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

struct Cow {
    int w;
    int s;

    bool operator < (const Cow &other) {
        return w + s < other.w + other.s;   // 按照w + s从小到大排序
    }
}cow[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) scanf("%d%d", &cow[i].w, &cow[i].s);

    sort(cow, cow + n);
    int sum = 0;
    int risk = -2e9;
    for(int i = 0; i < n; i ++)
    {
        risk = max(risk, sum - cow[i].s);
        sum += cow[i].w;
    }

    cout << risk << endl;
    return 0;
}
