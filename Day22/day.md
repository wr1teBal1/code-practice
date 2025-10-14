# 回溯算法part01

---

### 理论基础 

[题目链接/文章讲解](https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)

回溯函数也就是递归函数，指的都是一个函数。

回溯法，一般可以解决如下几种问题：

- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几 种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

回溯法解决的问题都可以抽象为树形结构，是的，我指的是所有回溯法的问题都可以抽象为树形结构！

因为回溯法解决的都是在集合中递归查找子集，集合的大小就构成了树的宽度，递归的深度就构成了树的深度。

递归就要有终止条件，所以必然是一棵高度有限的树（N叉树）。

溯算法模板框架如下：

~~~c++
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
~~~
###  77. 组合

[题目链接/文章讲解](https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html)

根据模板不难写出
```c++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> comb;
    void backtrack(int n, int k, int start) {
        for(int i = start; i <= n; ++i) {
            comb.push_back(i);
            if (comb.size() == k) {
                res.push_back(comb);
            } else {
                backtrack(n, k, i + 1);
            }
            comb.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }
};
```


###  216.组合总和III 


[题目链接/文章讲解](https://programmercarl.com/0216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII.html)

配合ai修正错误写出
```c++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> comb;
    void backtrack(int k, int n, int start, int sum) {
        if (comb.size() == k) {
            if (sum == n) {
                res.push_back(comb);
            }
            return; // 无论总和是否为n，都终止递归
        }
        if(sum >= n)return;
        for (int i = start; i <= 9; i++) {
            comb.push_back(i); // 处理节点
            sum += i;
            backtrack(k, n, i + 1,sum); // 递归
            comb.pop_back(); // 回溯，撤销处理的节点
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,1,0);
        return res;
    }
};
```

错误有两处

1. 返回结果部分情况考虑不全
2. 回溯部分没有回溯sum

###  17.电话号码的字母组合 


[题目链接/文章讲解](https://programmercarl.com/0017.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.html)


自己写的时候思路是对的，但是有若干错误

```c++
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
```
