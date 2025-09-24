# 第四章 字符串part01
---
### 344.反转字符串

[题目链接/文章讲解](https://programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html)

这道题循环一边也是超级简单的

但是题目中说到不能使用额外空间，所以一时也想不出办法

__一开始以为不能使用额外空间连中间值都不能使用__

答案中就用到了swap()

解决了这个问题的同时还只需循环到一半就可以了

~~~c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }
};
~~~



###  541. 反转字符串II

[题目链接/文章讲解](https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html)

复杂版的反转字符串，加了几个逻辑，而且可以套用上一题的函数

~~~c++
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
~~~


### 卡码网：54.替换数字

[题目链接/文章讲解](https://programmercarl.com/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.htmlhttps://programmercarl.com/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html)

一秒做完
~~~c++
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
~~~

