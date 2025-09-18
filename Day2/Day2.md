# 数组2
---
## 209.长度最小的数组
[题目链接]()
[题目解析]()

第一眼以为排序一下从末尾叠加就好了，没懂题目“连续数组”的意义
~~~c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int add=0;
        for(int i=nums.size()-1;i>=0;i--){
            add+=nums[i];
            if(add>=target){
                return nums.size()-i;
            }
        }
        return 0;
    }
};
~~~

然后思路全无，直接看一眼ai的解答吧
解法说明：

1. **滑动窗口思想**：使用两个指针（left 和 right）表示当前子数组的范围
2. **扩展窗口**:right 指针向右移动，将元素加入当前和
3. **收缩窗口**:当当前和大于等于 target 时，尝试移动 left 指针缩小窗口，以寻找更短的符合件的子数组
4. **记录最小值**：每次找到符合条件的子数组时，更新最小长度

按照自己的思路写一下

~~~c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        while(right < nums.size()){
            sum += nums[right];
            right++;
            while(sum >= target){
                if(sum >= target)sum -= nums[left],left++;
            }
            if (sum >= target)
            {
                return right - left;
            }
        }
        return 0;
    }
};
~~~

这次写的逻辑混乱，第一次符合条件后他就开始减左边，减完还符合就直接输出了，导致答案在数组中间，并非最小数组

这次添加最小数组长度记录和旗帜，让整个数组循环一遍
通过
~~~c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int min = nums.size();
        int flag = 0;
        while(right < nums.size()){
            sum += nums[right];
            right++;
            while(sum >= target){
                flag = 1;
                if(sum - nums[left] >= target)sum -= nums[left],left++;
                else break;
            }
            if (sum >= target && right - left <= min)min = right - left;
        }
        if(flag == 0)return 0;
        return min;
    }
};
~~~




## 59.螺旋矩阵II

[题目链接](https://leetcode.cn/problems/spiral-matrix-ii/)
[题目解析](https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html)

这个题一边过
~~~c++
class Solution {
public:
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    int num = 1;
    
    while (num <= n * n) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    return matrix;
}
};
~~~

## 58.区间和（卡农）

[题目解析](https://www.programmercarl.com/kamacoder/0058.%E5%8C%BA%E9%97%B4%E5%92%8C.html)

没看懂题目提示前缀和是什么东西~~没学过~~
写了这一坨，超时了
~~~c++
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int a, b;
    while (cin >> a >> b) {
        int sum = 0;
        for (int i = a; i <= b; ++i) {
            sum += arr[i];
        }
        cout << sum << endl;
    }

    return 0;
}
~~~
运用前缀和后
~~~c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 构建前缀和数组
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int a, b;
    while (cin >> a >> b) {
        // 区间和 = 前缀和[b+1] - 前缀和[a]
        int sum = prefix[b + 1] - prefix[a];
        cout << sum << endl;
    }

    return 0;
}
    
~~~
这个思路太巧秒了只能说



## 44.开发商购买土地（卡农）

[题目解析](https://www.programmercarl.com/kamacoder/0044.%E5%BC%80%E5%8F%91%E5%95%86%E8%B4%AD%E4%B9%B0%E5%9C%9F%E5%9C%B0.html#%E6%80%9D%E8%B7%AF)

一遍过
~~~c++
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            totalSum += grid[i][j];
        }
    }
    int minDiff = INT_MAX;
    // 横向划分
    for (float a = 0.5; a < n ; ++a){
        int sum = 0;
        for(int j = 0; j <= a; ++j){
            for(int k = 0; k < m; ++k){
                sum += grid[j][k];
            }
        }
        int diff = abs(totalSum - 2 * sum);
        if(diff < minDiff) minDiff = diff;
    }
    // 纵向划分
    for (float a = 0.5; a < m ; ++a){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k <= a; ++k){
                sum += grid[j][k];
            }
        }
        int diff = abs(totalSum - 2 * sum);
        if(diff < minDiff) minDiff = diff;
    }
    cout << minDiff << endl;
    return 0;
}
~~~