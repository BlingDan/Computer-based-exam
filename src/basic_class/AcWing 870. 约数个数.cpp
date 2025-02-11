#include <iostream>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;
int n;
unordered_map<int ,int> primes;

int main()
{
    cin >> n;
    while(n --)
    {
        int a;
        cin >> a;
        for(int i = 2; i <= a / i; i ++)
        {
            /**
             * 是while不是if
             */
            while(a % i == 0){
                primes[i] ++;
                a /= i;
            }
        }
        if(a > 1) primes[a] ++;
    }
    long long res = 1;
    for(auto prime : primes) res = res * (prime.second + 1) % MOD;

    cout << res << endl;
}
