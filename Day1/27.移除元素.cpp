/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int max = nums.size() - 1;
            int i = 0;
            while (i <= max) {
                if (nums[i] == val) {
                    nums[i] = nums[max];
                    max--;
                } else {
                    i++;
                }
            }
            return i;
        }
    };
// @lc code=end

