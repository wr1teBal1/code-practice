# 回溯算法 part04

### 491.递增子序列

[题目链接/文章讲解](https://programmercarl.com/0491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.html)

我本来写一个删除函数，让小与前面的直接删除，忽略了即使比前一个小也可能成立
```c++
    void del(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if (nums[i-1]>nums[i]){
                nums.erase(nums.begin()+i);
            }
        }
        return;
    }
```

很有难度，没想到可以用set查重
~~~c++
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        int used[201] = {0}; // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                    || used[nums[i] + 100] == 1) {
                    continue;
            }
            used[nums[i] + 100] = 1; // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
~~~


### 46.全排列

[题目链接/文章讲解](https://programmercarl.com/0046.%E5%85%A8%E6%8E%92%E5%88%97.html)

用了一个bool列判断用没用过，真的很难想

```c++
class Solution {
    private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used){
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;   
    }
};
```



### 47.全排列 II 


[题目链接/文章讲解](https://programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html)

跳过的逻辑很难理解

```c++
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
```


### 332.重新安排行程（建议跳过，力扣修改后台数据，应该不能用回溯了）

[题目链接/文章讲解](https://programmercarl.com/0332.%E9%87%8D%E6%96%B0%E5%AE%89%E6%8E%92%E8%A1%8C%E7%A8%8B.html)


### 51.N皇后（适当跳过）

[题目链接/文章讲解](https://programmercarl.com/0051.N%E7%9A%87%E5%90%8E.html)


### 37.解数独（适当跳过）

[题目链接/文章讲解](https://programmercarl.com/0037.%E8%A7%A3%E6%95%B0%E7%8B%AC.html)


### 总结

[总结](https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E6%80%BB%E7%BB%93.html)
