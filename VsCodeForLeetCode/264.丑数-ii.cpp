/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i = 2; i <= n; i ++)
        {
            int n2 = dp[p2] * 2;
            int n3 = dp[p3] * 3;
            int n5 = dp[p5] * 5;
            
            dp[i] = min(min(n2, n3), n5);
            {
                if(dp[i] == n2) {
                    p2 ++;
                }
                if(dp[i] == n3) {
                    p3 ++;
                }
                if(dp[i] == n5) {
                    p5 ++;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

