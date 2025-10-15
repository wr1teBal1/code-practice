# 回溯算法part03

### 93.复原IP地址  


[题目链接/文章讲解](https://programmercarl.com/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.html)

自己的思路和答案几乎一样，但是逻辑上的问题自己无法实现，这道题有点难度qwq

```c++
class Solution {
private:
    vector<string> res;       // 存储最终结果
    vector<string> path;      // 存储当前分割的IP段（如["192", "168"]）

    // 检查当前段是否合法（修正：参数改为string，处理单段）
    bool is_valid(const string& segment) {
        int n = segment.size();
        // 1. 长度必须在1-3之间
        if (n < 1 || n > 3) return false;
        // 2. 不能有前导零（长度>1时首字符不能为'0'）
        if (n > 1 && segment[0] == '0') return false;
        // 3. 数值必须≤255
        int num = stoi(segment);
        return num <= 255;
    }

    // 递归函数（修正：sum改为当前正在拼接的段，增加count记录已分割段数）
    void bac(const string& s, int start, int count, string current_segment) {
        // 终止条件：分割出4段且用完所有字符
        if (count == 4) {
            if (start == s.size()) {
                // 拼接4段为IP地址
                string ip;
                for (int i = 0; i < 4; ++i) {
                    ip += path[i];
                    if (i != 3) ip += ".";
                }
                res.push_back(ip);
            }
            return;
        }

        // 枚举当前段的结束位置（最多3位）
        for (int i = start; i < s.size() && i - start < 3; ++i) {
            // 截取当前段（从start到i的子串）
            current_segment = s.substr(start, i - start + 1);
            if (is_valid(current_segment)) {
                path.push_back(current_segment);  // 加入当前段
                bac(s, i + 1, count + 1, "");     // 递归下一段（重置当前段）
                path.pop_back();                  // 回溯
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        path.clear();
        // 剪枝：IP地址总长度必须在4-12之间（4段，每段1-3位）
        if (s.size() < 4 || s.size() > 12) {
            return res;
        }
        bac(s, 0, 0, "");  // 初始：从0开始，已分割0段，当前段为空
        return res;
    }
};
```


### 78.子集

[题目链接/文章讲解](https://programmercarl.com/0078.%E5%AD%90%E9%9B%86.html)

有点简单

```c++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;   
    }
};
~~~

###  90.子集II 


[题目链接/文章讲解](https://programmercarl.com/0090.%E5%AD%90%E9%9B%86II.html)

这两道题都简单的
跟昨天的差不多
```c++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            // 去重逻辑
            if (i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序，方便去重
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};
```