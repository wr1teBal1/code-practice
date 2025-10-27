# 动态规划part04



### 1049. 最后一块石头的重量 II 


[题目解析及链接](https://programmercarl.com/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.html)


一堆的石头重量是sum，那么我们就尽可能拼成 重量为 sum / 2 的石头堆。 这样剩下的石头堆也是 尽可能接近 sum/2 的重量。 那么此时问题就是有一堆石头，每个石头都有自己的重量，是否可以 装满 最大重量为 sum / 2的背包。

这题跟前天一样，但是隔两天全忘了
~~~c++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) sum += stones[i];
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) { // 遍历物品
            for (int j = target; j >= stones[i]; j--) { // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

~~~


###  494. 目标和

[题目解析及链接](https://programmercarl.com/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.html)

转换为背包问题很难理解

~~~c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (abs(target) > sum) return 0; // 此时没有方案
        if ((target + sum) % 2 == 1) return 0; // 此时没有方案
        int bagSize = (target + sum) / 2;
        
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));
        
        // 初始化最上行
        if (nums[0] <= bagSize) dp[0][nums[0]] = 1; 

        // 初始化最左列，最左列其他数值在递推公式中就完成了赋值
        dp[0][0] = 1; 

        int numZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) numZero++;
            dp[i][0] = (int) pow(2.0, numZero);
        }

        // 以下遍历顺序行列可以颠倒
        for (int i = 1; i < nums.size(); i++) { // 行，遍历物品
            for (int j = 0; j <= bagSize; j++) { // 列，遍历背包
                if (nums[i] > j) dp[i][j] = dp[i - 1][j]; 
                else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            }
        }
        return dp[nums.size() - 1][bagSize];
    }
};
~~~



###  474.一和零  


[题目解析及链接](https://programmercarl.com/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.html)


答案的思路能理解，但是自己这捏不出来了