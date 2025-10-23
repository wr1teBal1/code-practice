/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// class Solution {
// public:
//     int fib(int n) {
//         if(n==0) return 0;
//         if(n==1) return 1;
//         return fib(n-1)+fib(n-2);
//     }
// };


class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};
// @lc code=end

