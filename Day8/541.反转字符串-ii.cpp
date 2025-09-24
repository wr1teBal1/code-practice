/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.size() <= k) {
             for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
            }
            return s;
        }
        for(int i = 0; i < s.size(); i += 2*k) {
            int j = min(i + k - 1, (int)s.size() - 1);
            for(int p = i, q = j; p < q; p++, q--) {
                swap(s[p], s[q]);
            }
        }
        return s;
    }
};
// @lc code=end

