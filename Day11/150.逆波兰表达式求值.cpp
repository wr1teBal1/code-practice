/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> stk;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (token == "+") {
                    stk.push(a + b);
                } else if (token == "-") {
                    stk.push(a - b);
                } else if (token == "*") {
                    stk.push(a * b);
                } else if (token == "/") {
                    stk.push(a / b);
                }
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
// @lc code=end

