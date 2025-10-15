/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            // 去重逻辑
            if (i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序，方便去重
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

