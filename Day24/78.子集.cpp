/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;   
    }
};
// @lc code=end

