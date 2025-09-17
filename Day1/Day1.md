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
---

## 27.移除元素

[题目链接](https://leetcode.cn/problems/binary-search/)

[文章讲解](https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html)

第一遍用的最常见的双循环解法
~~~因为还不会什么双指针~~~

~~~c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == val){
                for(int j = i; j<nums.size()-1;j++){
                    nums[j] = nums[j+1];
                }
                count++;
                i--;
            }

        }
        return nums.size() - count;
    }
};
~~~

再次修改后
~~~c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int max = nums.size()-1;
        for(int i = 0; i<max;){
            if(nums[i] == val){
                count++;
                while(max >= i && nums[max]==val){
                    count++;
                    max--;
                }
                if(max>i){
                    nums[i] = nums[max];
                    max--;
                    i++;
                }else {
                    break;
                }
            }else{
                i++;
            }
        }
        return nums.size() - count;
    }
};
~~~
当输入是 nums = [1]，val = 1 时，期望结果是数组变为空（即前 0 个元素是不等于 val 的元素，虽然数组实际还有元素，但题目关注前 k 个），返回 0。而你代码输出数组还是 [1]，返回的是 nums.size() - count，此时 count 计算可能有误，导致返回不符合预期。

用ai帮我简化了一下逻辑，简洁明了完成题目
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

## 977.有序数组的平方

[题目链接](https://leetcode.cn/problems/squares-of-a-sorted-array/)

[文章讲解](https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html)

写到这里发现自己双数组还是没有完全掌握
自己写了几个方案，总是有过不去的案例，但至少都是尝试用双数组去写的
直接写两个循环应该所有人都会hhh
但是写了一个逃课答案
~~~c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
~~~
直接参考一下答案吧qwq
~~~C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
~~~
自己完全没有想到可以再建一个空数组，自己之前的思路大抵就是这种
---
今天的打卡也是结束了O.o
数组这块大学课上也是了解了大部分，双指针思想也学过，但是不能活用，希望这次过后可以灵活运用