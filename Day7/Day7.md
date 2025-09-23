# 哈希表 Part2

### 454.四数相加II

[题目链接/文章讲解](https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html)

看似和昨天的两数相加差不多，但是我一点思路也没有qwq

本题解题步骤：
1. 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
2. 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
3. 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
4. 再遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
5. 最后返回统计值 count 就可以了

代码写出来就是这样
~~~c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(-(c + d)) != umap.end()) {
                    count += umap[-(c + d)];
                }
            }
        }
        return count;
    }
};
~~~


### 383. 赎金信

[题目链接/文章讲解](https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html)

通过前几道哈希表的题，这道题变得异常简单
~~~c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;
        for (char c : magazine) {
            charCount[c]++;
        }
        for (char c : ransomNote) {
            if (charCount[c] > 0) {
                charCount[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
~~~

### 15. 三数之和

[题目链接/文章讲解](https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html)

不是很会做，直接看答案解析，[源码点此](./15.三数之和.cpp)

### 18. 四数之和

[题目链接/文章讲解](https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html)

跟第三题是一样的的思路，直接拿下了