# 贪心算法 part04

### 452. 用最少数量的箭引爆气球


[题目链接与解析](https://programmercarl.com/0452.%E7%94%A8%E6%9C%80%E5%B0%91%E6%95%B0%E9%87%8F%E7%9A%84%E7%AE%AD%E5%BC%95%E7%88%86%E6%B0%94%E7%90%83.html)

首先快排我好像没学过

他利用sort自定义函数cmp
将位置的最左端从小到大排序

~~~c++
        static bool cmp(const vector<int>& a, const vector<int>& b) {   
            return a[1] < b[1];
        }

~~~

然后判断下一个位置最左侧与上一个最右侧的大小

~~~c++
class Solution {
    private:
        static bool cmp(const vector<int>& a, const vector<int>& b) {   
            return a[1] < b[1];
        }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), cmp);
        int arrows = 1;
        for (int i = 1, n = points.size(); i < n; ++i) {
            if (points[i][0] > points[i - 1][1]) {
                ++arrows;
            }
            else {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }

        return arrows;
    }
};
~~~

### 435. 无重叠区间

[题目链接与解析](https://programmercarl.com/0435.%E6%97%A0%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4.html)

答案一个很重要的思路是，只要找到没有重叠的所有区间之和，然后再用区间总数去减掉，剩下的就是需要移除的区间数量

~~~c++
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int count = 1;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                ++count;
                end = intervals[i][1];
            }
        }

        return intervals.size() - count;   
    }
};
~~~



### 763.划分字母区间

[题目链接与解析](https://programmercarl.com/0763.%E5%88%92%E5%88%86%E5%AD%97%E6%AF%8D%E5%8C%BA%E9%97%B4.html)


**如果找到之前遍历过的所有字母的最远边界，说明这个边界就是分割点了**

~~~c++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
~~~