/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    //小顶堆
    class mycomparison{
    public:
        bool operator() (const pair<int, int>& a,const pair<int, int> b) {
            return a.second > b.second; // 频率小的元素优先级高
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> map; // 记录每个元素的频率
        for (int i=0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> minHeap; // 小顶堆

        for (auto it = map.begin(); it != map.end(); it++) {
            minHeap.push({it->first, it->second});
            if (minHeap.size() > k) {
                minHeap.pop(); // 保持堆的大小为 k
            }
        }
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return result;
    }
};
// @lc code=end

