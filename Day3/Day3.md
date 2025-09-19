# 链表
---

## 链表基础理论

[链表基础理论文章讲解](https://programmercarl.com/%E9%93%BE%E8%A1%A8%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)

#### 单链表
“链表是一种通过指针串联在一起的线性结构，每一个节点由两部分组成，一个是数据域一个是指针域（存放指向下一个节点的指针），最后一个节点的指针域指向null（空指针的意思）。”

简单来说数组在内存中的存放是连续的，可是链表是随机的，两个相邻的指针中，前一部分是数据额，后一部分是下一个数据的存放地址

#### 双链表
单链表中的指针域只能指向节点的下一个节点。

双链表:每一个节点有两个指针域，一个指向下一个节点，一个指向上一个节点。

双链表 既可以向前查询也可以向后查询。

#### 循环列表
循环链表，顾名思义，就是链表首尾相连。

循环链表可以用来解决约瑟夫环问题。

#### 列表定义
~~~c++
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
~~~

## 203.移除链表元素

[题目链接/解析](https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE)

因为还不会运用链表，这题先直接看答案

~~~c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
~~~

通过这个题，理解了链表中数值的调用（地址的调用）和虚表头的使用，接下来看一下这个题的递归做法

~~~c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 基础情况：空链表
        if (head == nullptr) {
            return nullptr;
        }

        // 递归处理
        if (head->val == val) {
            ListNode* newHead = removeElements(head->next, val);
            delete head;
            return newHead;
        } else {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};
~~~

1. 先一直递归到链表末尾（触发终止条件）
2. 然后从末尾开始 "回溯"，依次判断每个节点是否需要删除
3. 最终将所有不需要删除的节点重新连接，形成新的链表

## 707.设计链表

[题目链接/解析](https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html)


自己写的时候把节点的类当成链表的类，没有去另写一个类，可能导致类的混乱，看了答案，一目了然

这下对链表和节点的认识更进一步

[源码点此](./707.设计链表.cpp)

##  206.反转链表

[题目链接/文章讲解/视频讲解](https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html)

第一眼 想用一层for循环去找到next是空指针的最后一位，然后再用二层for去传递他的上一层指针

然后觉得有点复杂就去用了递归
三五行就解决了答案

~~~c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
~~~

---
学习了链表的基础知识，复习递归，类，结构体的使用