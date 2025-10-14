/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> comb;
    void backtrack(int k, int n, int start, int sum) {
        if (comb.size() == k) {
            if (sum == n) {
                res.push_back(comb);
            }
            return; // 无论总和是否为n，都终止递归
        }
        if(sum >= n)return;
        for (int i = start; i <= 9; i++) {
            comb.push_back(i); // 处理节点
            sum += i;
            backtrack(k, n, i + 1,sum); // 递归
            comb.pop_back(); // 回溯，撤销处理的节点
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,1,0);
        return res;
    }
};
// @lc code=end

