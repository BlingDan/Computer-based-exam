#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
int a;

int main()
{

    cin >> n;
    while(n --)
    {
        cin >> a;
        vector<int> v;
        for(int i = 1; i < a / i; i ++)
        {
            if(a % i == 0){
                v.push_back(i);
                if(i != a / i)
                    v.push_back(a / i);
            }
        }

        sort(v.begin(), v.end());
        for(auto it = v.begin(); it != v.end(); it ++)
            cout << *it << ' ';
        cout << endl;
    }
}
