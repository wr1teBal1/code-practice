/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
    private:
        static bool cmp(const vector<int>& a, const vector<int>& b) {   
            return a[1] < b[1];
        }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), cmp);
        int arrows = 1;
        for (int i = 1, n = points.size(); i < n; ++i) {
            if (points[i][0] > points[i - 1][1]) {
                ++arrows;
            }
            else {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }

        return arrows;
    }
};
// @lc code=end

