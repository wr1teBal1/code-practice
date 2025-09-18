/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    int num = 1;
    
    while (num <= n * n) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    return matrix;
}
};
// @lc code=end

