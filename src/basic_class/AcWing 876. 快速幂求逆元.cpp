#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
    int res = 1;
    while(b)
    {
        if(b & 1) {
            res = (LL) res * a % p;
        }
        a = (LL) a * a % p;
        b = b >> 1;
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    int a, b, p;
    while(n --)
    {
        scanf("%d%d", &a, &p);
        int res = qmi(a, p - 2, p);

        if(a % p) cout << res << endl;
        else cout << "impossible" << endl;
    }
}
