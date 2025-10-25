# 动态规划part02

### 62.不同路径

[题目解析及连接](https://programmercarl.com/0062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.html)

答案的一种思路

其实机器人走过的路径可以抽象为一棵二叉树，而叶子节点就是终点！


此时问题就可以转化为求二叉树叶子节点的个数

~~~c++
class Solution {
private:
    int dfs(int i, int j, int m, int n) {
        if (i > m || j > n) return 0; // 越界了
        if (i == m && j == n) return 1; // 找到一种方法，相当于找到了叶子节点
        return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        return dfs(1, 1, m, n);
    }
};
~~~


~~~c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
~~~

难道说动态规划就是重新演变一下答案？


### 63. 不同路径 II

[题目解析及连接](https://programmercarl.com/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.html)

对比上一题多了点条件

~~~c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
~~~


### 343. 整数拆分 （可跳过）


[题目解析及连接](https://programmercarl.com/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.html)


### 96.不同的二叉搜索树 （可跳过）


[题目解析及连接](https://programmercarl.com/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html)



