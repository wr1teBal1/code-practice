/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) return false; // 遇到右括号时，栈为空，说明不匹配
                char top = stk.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    stk.pop(); // 匹配成功，弹出栈顶元素
                } else {
                    return false; // 不匹配
                }
            }
        }
        return stk.empty();
         // 最后栈为空则匹配成功，否则不匹配
    }
};
// @lc code=end

