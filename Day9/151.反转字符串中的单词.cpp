/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size()-1; i++)
        {
            if (s[i] == ' ' && s[i+1] == ' ')
            {
                s.erase(i,1);
                i--;
            }
            while (s[0] == ' ')
            {
                s.erase(0,1);
            }
            while (s[s.size()-1] == ' ')
            {
                s.erase(s.size()-1,1);
            }
        }
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
        for (int i = 0; i < s.size()-1; i++){
            int j = i+1;
            if(i == 0){
                for(; s[j]!=' ';j++){
                    if (j == s.size()-1)
                    {
                        for (int p = i, q = j; p < q; p++, q--) {
                            swap(s[p],s[q]);
                        }
                        return s;
                    }
                }
                for (int p = i, q = j-1; p < q; p++, q--) {
                    swap(s[p],s[q]);
                }
            }
            if(s[i] == ' '){
                for(; s[j]!=' ';j++){
                    if (j == s.size()-1)
                    {
                        for (int p = i+1, q = j; p < q; p++, q--) {
                            swap(s[p],s[q]);
                        }
                        return s;
                    }
                }
                for (int p = i+1, q = j-1; p < q; p++, q--) {
                    swap(s[p],s[q]);
                }
            }
        }
        return s;
    }
};
// @lc code=end

