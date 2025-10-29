/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int bagSize = amount;

        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(bagSize + 1, 0));

        // 初始化最上行
        for (int j = 0; j <= bagSize; j++) {
            if (j % coins[0] == 0) dp[0][j] = 1;
        }
        // 初始化最左列
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }
        // 以下遍历顺序行列可以颠倒
        for (int i = 1; i < coins.size(); i++) { // 行，遍历物品
            for (int j = 0; j <= bagSize; j++) { // 列，遍历背包
                if (coins[i] > j) dp[i][j] = dp[i - 1][j]; 
                else dp[i][j] = dp[i - 1][j] +  dp[i][j - coins[i]];
            }
        }
        return dp[coins.size() - 1][bagSize];
    }
};
// @lc code=end

