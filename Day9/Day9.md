# 字符串part02

---

### 151.翻转字符串里的单词

[题目链接/文章讲解](https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html)

这题看了答案思路后为了过案例自己写出来像依托

为了过案例的特殊情况写了好多if语句

~~~c++
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size()-1; i++)
        {
            if (s[i] == ' ' && s[i+1] == ' ')
            {
                s.erase(i,1);
                i--;
            }
            while (s[0] == ' ')
            {
                s.erase(0,1);
            }
            while (s[s.size()-1] == ' ')
            {
                s.erase(s.size()-1,1);
            }
        }
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
        for (int i = 0; i < s.size()-1; i++){
            int j = i+1;
            if(i == 0){
                for(; s[j]!=' ';j++){
                    if (j == s.size()-1)
                    {
                        for (int p = i, q = j; p < q; p++, q--) {
                            swap(s[p],s[q]);
                        }
                        return s;
                    }
                }
                for (int p = i, q = j-1; p < q; p++, q--) {
                    swap(s[p],s[q]);
                }
            }
            if(s[i] == ' '){
                for(; s[j]!=' ';j++){
                    if (j == s.size()-1)
                    {
                        for (int p = i+1, q = j; p < q; p++, q--) {
                            swap(s[p],s[q]);
                        }
                        return s;
                    }
                }
                for (int p = i+1, q = j-1; p < q; p++, q--) {
                    swap(s[p],s[q]);
                }
            }
        }
        return s;
    }
};
~~~


### 卡码网：55.右旋转字符串

[题目链接/文章讲解](https://programmercarl.com/kamacoder/0055.%E5%8F%B3%E6%97%8B%E5%AD%97%E7%AC%A6%E4%B8%B2.html)

新建一个额外字符串的话这道题很简单，但是我没有想到不用额外空间该怎么做

看的答案的思路一秒就懂了，确实有思路了就很简单


