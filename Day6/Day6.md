# 哈希表Part1

---

### 哈希表理论基础

[哈希表讲解](https://programmercarl.com/%E5%93%88%E5%B8%8C%E8%A1%A8%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)

什么时候用哈希法：__当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法__

但是哈希法也是 __牺牲了空间换取了时间__ ，因为我们要使用额外的数组，set或者是map来存放数据，才能实现快速的查找。

###  242.有效的字母异位词

[题目详情/解析](https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html)


这道题只需想办法把其中一个转化成哈希表，再用第一个去遍历检索哈希表就可以了

但是自己还不会直接运用哈希表，所以直接看答案

~~~c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};
~~~

答案这里是，写入表的时候+操作，检索到就-操作，最后数组不为0就是字母不一样

###  349. 两个数组的交集

[题目链接/文章讲解](https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html)

可以直接套用第一题的思路如下
~~~c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int record[1001] = {0};
        for (int i = 0; i < nums1.size(); i++) {
            record[nums1[i]]=1;
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            if (record[nums2[i]] == 1){
                res.push_back(nums2[i]);
                record[nums2[i]] = 0;
            }
        }

        return res;

    }
};
~~~

在看看答案的解法
~~~c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num : nums2) {
            if (s1.find(num) != s1.end()) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());

    }
};
~~~

跟我第一个题的思路一样，先存到哈希表中在遍历下寻找一遍

### 202. 快乐数

[题目链接/文章讲解](https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html)

对于这个题怎么使用哈希表没有什么思路

先看答案
~~~C++
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
~~~
先写了一个函数用来求平方和

然后看主函数
~~~c++
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
~~~

如果不是欢乐数，就会出现循环，会出现相同数值，将出现过的数值存放在哈希表中，每次算出后在表中检索，检索到重复的值就返回false




###  1. 两数之和 

[题目链接/文章讲解](https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html)

这道题只需遍历一遍然后添加到map中保存下标和值
然后第二遍遍历与目标值相减搜索map

但是答案的意思是边遍历边搜索，这样只需遍历一次

~~~c++
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
~~~