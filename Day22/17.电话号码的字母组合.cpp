/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> res;
    string comb;
    vector<string> phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void bac(string digits,int start){
        if (start == digits.size()) {
            if (!comb.empty()) {  // 避免 digits 为空时加入空字符串
                res.push_back(comb);
            }
            return;
        }
        int digit = digits[start] - '0';  // 字符转数字（如 '2' -> 2）
        string& letters = phone[digit];
        //之前我是这样写的   comb.push_back(phone[digits[start]][i]);       
        //没有考虑到digits[start]是字符 需要-'0'转为数字


        // for(int i = 0 ; i < 4 ; i++){
        //     comb.push_back(phone[digits[start]][i]);
        //     bac(digits,start+1);
        //     comb.pop_back();
        // }

        //我这样写的是错误的 因为有些数字对应的字母少于4个
        //改成下面这样
        for (char c : letters) {
            comb.push_back(c);          // 选择当前字母
            bac(digits, start + 1);  // 递归处理下一个数字
            comb.pop_back();            // 回溯，撤销选择
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        bac(digits,0);
        return res;
    }
};
// @lc code=end

