/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0;i < nums.size();i++){
            if (nums[i] > 0) break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环 
            if (i > 0 && nums[i] == nums[i-1]) continue; // 去重
            unordered_set<int> s;
            for (int j = i + 1; j < nums.size(); j++) {
                if(j > i+2&&nums[j]==nums[j-1]&&nums[j-1]==nums[j-2]) continue; // 去重
                int target = -nums[i] - nums[j];
                if (s.find(target)!= s.end()) {
                    res.push_back({nums[i], nums[j], target});
                    s.erase(target);
                } 
                else {
                    s.insert(nums[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

