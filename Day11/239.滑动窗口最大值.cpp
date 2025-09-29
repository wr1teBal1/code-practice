/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

class MyQueue{
    public:
    deque<int> que;
    void push(int n) {
        while (!que.empty() && que.back() < n) {
            que.pop_back();
        }
        que.push_back(n);
    }
    void pop(int n) {
        if (!que.empty() && que.front() == n) {
            que.pop_front();
        }
    }
    int front() {
        return que.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue myque;
        for (int i = 0; i < k; i++) {
            myque.push(nums[i]);
        }
        result.push_back(myque.front());
        for (int i = k; i < nums.size(); i++) {
            myque.pop(nums[i - k]);
            myque.push(nums[i]);
            result.push_back(myque.front());
        }
        return result;
    }
};
// @lc code=end

