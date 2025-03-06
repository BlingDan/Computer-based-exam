/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
#define N = 1010;
#define MOD = 1e7 + 10;
public:
    int numDistinct(string s, string t) {
        int f[N][N];
        int n = s.size();
        int m = t.size();

        for(int i = 0; i <= s.size(); i ++) {
            f[i][0] = 1;
        }

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(s[i - 1] == t[j - 1])
                {
                    f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
                }
                else {
                    f[i][j] = f[i - 1][j] % MOD;
                }
            }
        }

        return f[n][m];
    }
};
// @lc code=end

