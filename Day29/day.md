# 贪心算法 part03


### 134. 加油站

[题目链接](https://programmercarl.com/0134.%E5%8A%A0%E6%B2%B9%E7%AB%99.html)

这个局部最优怎么也想不出来吧，就算看答案我也很长时间才能看懂

```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};
```




### 135. 分发糖果 


[题目链接](https://programmercarl.com/0135.%E5%88%86%E5%8F%91%E7%B3%96%E6%9E%9C.html)

我一开始以为整理一下数列就好做了，忘了孩子们的顺序不能动

```c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        sort(ratings.begin(), ratings.end());
        int n = ratings.size();
        int res = n; // 每人至少一个糖果
        int candy = 0;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1] && candy >= 0) {
                candy++;
            } else if (ratings[i] == ratings[i - 1] && candy > 0) {
                candy -= 1;
            }
            res += candy;
        }
        return res;
    }

};
```

原来只需要顾着眼前遍历两次就可以了

~~~c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};
~~~



### 860.柠檬水找零

[题目链接](https://programmercarl.com/0860.%E6%9F%A0%E6%AA%AC%E6%B0%B4%E6%89%BE%E9%9B%B6.html)

按照自己的思路写出来了

~~~c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};
~~~
不知道贪心在哪

原来是 **优先消耗**


### 406.根据身高重建队列

[题目链接](https://programmercarl.com/0406.%E6%A0%B9%E6%8D%AE%E8%BA%AB%E9%AB%98%E9%87%8D%E5%BB%BA%E9%98%9F%E5%88%97.html)

好难qwq