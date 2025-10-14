/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> comb;
    void backtrack(int n, int k, int start) {
        for(int i = start; i <= n; ++i) {
            comb.push_back(i);
            if (comb.size() == k) {
                res.push_back(comb);
            } else {
                backtrack(n, k, i + 1);
            }
            comb.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }
};
// @lc code=end

