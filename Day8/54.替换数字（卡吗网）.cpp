#include <iostream>
#include <vector>

using namespace std;

// 题目描述
// 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
// 输入描述
// 输入一个字符串 s,s 仅包含小写字母和数字字符。
// 输出描述
// 打印一个新的字符串，其中每个数字字符都被替换为了number
// 输入示例
// a1b2c3
// 输出示例
// anumberbnumbercnumber
// 提示信息
// 数据范围：
// 1 <= s.length < 10000。

int main() {
    string s;
    cin >> s;
    string result;
    for (char c : s) {
        if (isdigit(c)) {
            result += "number";
        } else {
            result += c;
        }
    }
    cout << result << endl;
    return 0;
}