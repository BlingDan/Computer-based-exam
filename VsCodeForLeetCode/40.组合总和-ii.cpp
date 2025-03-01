/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
           
    }

private:
    void dfs(int cnt, int size, int res, int target, vector<int>& candidates)
    {
        if(cnt == size + 1)
            return;
        if(res + candidates[cnt - 1] > target)
            return;
        
        if(res + candidates[cnt - 1] == target)
    }
};
// @lc code=end

