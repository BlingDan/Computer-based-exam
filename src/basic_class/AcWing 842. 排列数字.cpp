#include <iostream>

using namespace std;

const int N = 1e6+10;
int m;
int path[N]; //mark dfs path
bool st[N]; //the number whether have traversal

/**
 *
 * n: the depth of recursion, don't worry whether it begin from 0 or 1
 * st[i]: in this algorith, it means the numer i whether have been traverasl
 */

void dfs(int n)
{
    //termination conditon
    if(n == m){
        for(int i = 0; i < m; i ++){
            cout << path[i] << ' ';
        }
        cout << endl;
    }

    //recursion
    for(int i= 1; i <= m; i ++)
    {
        if(st[i]) continue;
        path[n] = i;
        st[i] = true;
        dfs(n + 1);
        path[n] = 0;
        st[i] = false; //restore the scence
    }
}
int main()
{
    cin >> m;
    dfs(0);
    return 0;
}