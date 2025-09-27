# 栈与队列part01
---

### 理论基础

[理论基础](https://programmercarl.com/%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)

队列是先进先出，栈是先进后出

栈这里一点也没学过，所以只能一点一点看答案了



###  232.用栈实现队列

[题目链接/文章讲解](https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html)

理解下来发现栈就是一种储存数据的一种方式，对访问数据的方式有所要求

通过这一道题可以理解队列和栈


### 225. 用队列实现栈

[题目链接/文章讲解](https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html)

两个相似相反题目，其中可以用相同的做法

但是答案给了另一种只用一个队列就能实现模拟栈的做法

__一个队列在模拟栈弹出元素的时候只要将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部，此时再去弹出元素就是栈的顺序了。__

~~~c++
class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    int top(){
        int size = que.size();
        size--;
        while (size--){
            // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时获得的元素就是栈顶的元素了
        que.push(que.front());    // 将获取完的元素也重新添加到队列尾部，保证数据结构没有变化
        que.pop();
        return result;
    }

    bool empty() {
        return que.empty();
    }
};
~~~

###  20. 有效的括号

[题目链接/文章讲解](https://programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html)

知道了栈但是还不会运用，先看答案

答案列出三种情况

第一种情况：已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false

第二种情况：遍历字符串匹配的过程中，发现栈里没有要匹配的字符。所以return false

第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号return false

那么什么时候说明左括号和右括号全都匹配了呢，就是字符串遍历完之后，栈是空的，就说明全都匹配了

知道思路尝试自己写一下

~~~c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } 
            else {
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
~~~

### 1047. 删除字符串中的所有相邻重复项

[题目链接/文章讲解](https://programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html)

跟上一题思路差不多

独立完成

~~~c++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> word;
        for(char c : s){
            if(word.empty()){
                word.push(c);
            }
            else if(word.top() == c){
                word.pop();
            }
            else{
                word.push(c);
            }
        }
        string res;
        while(!word.empty()){
            res += word.top(); // 直接拼接字符，自动扩展字符串
            word.pop();
        }
        
        reverse(res.begin(), res.end()); // 反转得到正确顺序
        return res;
    }

};
~~~
