/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int min = nums.size();
        int flag = 0;
        while(right < nums.size()){
            sum += nums[right];
            right++;
            while(sum >= target){
                flag = 1;
                if(sum - nums[left] >= target){
                    sum -= nums[left],left++;
                    if (sum >= target && right - left <= min)min = right - left;
                }
                else break;
            }
            if (sum >= target && right - left <= min)min = right - left;
        }
        if(flag == 0)return 0;
        return min;
    }
};
// @lc code=end

