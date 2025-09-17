/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

//看到题目第一眼就联系标题想到用中间值一直二分下去找到目标值

//一开始只会用for循环写二分查找，后来看到题解用while循环写的更简洁
//并且while更加符合二分查找的思路