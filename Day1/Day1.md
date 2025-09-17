# 数组

---
## 27.二分查找

[题目链接](https://leetcode.cn/problems/binary-search/)

[文章讲解](https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html
)
我自己一开始看完题并结合题目就想到了用数学的二分法解题
~~因为浅陋的代码知识一开始用的for循环，很墨迹~~
所以最后使用的是题解中的while循环更简洁并且while更加符合二分查找的思路

### 最后解法
~~~c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
        
    }
};
~~~

## 27.移除元素

[题目链接](https://leetcode.cn/problems/binary-search/)

[文章讲解](https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html)

