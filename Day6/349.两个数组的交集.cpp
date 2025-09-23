/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         int record[1001] = {0};
//         for (int i = 0; i < nums1.size(); i++) {
//             record[nums1[i]]=1;
//         }
//         vector<int> res;
//         for (int i = 0; i < nums2.size(); i++) {
//             if (record[nums2[i]] == 1){
//                 res.push_back(nums2[i]);
//                 record[nums2[i]] = 0;
//             }
//         }

//         return res;

//     }
// };
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num : nums2) {
            if (s1.find(num) != s1.end()) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());

    }
};
// @lc code=end
