/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int k = 0; k <nums.size();k++){
            if (nums[k] > 0 && nums[k] > target) break; // 如果当前数字大于0，则4数之和一定大于0，所以结束循环
        
            if(k >0&& nums[k]==nums[k-1]) continue; // 去重
            for(int i = k + 1;i <nums.size();i++){
                if (nums[k] + nums[i] > target && nums[i] >=0) break; // 如果当前数字大于0，则4数之和一定大于0，所以结束循环
                if(i>k+1&& nums[i]==nums[i-1]) continue; // 去重
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right){
                    if((long)nums[k] +nums[i] +nums[left] + nums[right] == target){
                        result.push_back({nums[k],nums[i],nums[left],nums[right]});
                        while(left < right && nums[left]==nums[left+1]) left++; // 去重
                        while(left < right && nums[right]==nums[right-1]) right--; // 去重
                        left++;
                        right--;
                }
                    else if((long)nums[k] +nums[i] +nums[left] + nums[right] < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return result;
        
    }
};
// @lc code=end

