# 链表Part2
---
###  24. 两两交换链表中的节点 

[题目链接/解析](https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#%E6%80%9D%E8%B7%AF)

做题时一直想着可以通过循环去交换节点，但是想不出来该怎么找回到第一个值
看了答案才知道，虚拟表头的作用

~~~c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head; 
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* first = cur->next;
            ListNode* second = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = first;
            cur->next->next->next = second;

            cur = cur->next->next;
        }
        LisNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};
~~~

### 19.删除链表的倒数第N个节点

[题目链接/解析](https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html)

一开始我创建了一个快节点一个慢节点
但实际可以直接用原链表
第一版
~~~c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = new ListNode(0);
        ListNode* slow = new ListNode(0);
        fast->next = head;
        slow->next = head;
        while(slow != nullptr && n--) {
            slow = slow->next;
            if(n < 0) {
                fast = fast->next;
            }
            if(slow == nullptr) {
                break;
            }
        }
        ListNode* delNode = fast->next;
        fast->next = delNode->next;
        delete delNode;

        return head;
    }
};
~~~
但是这样要删除的是头节点时会出错

修改后
~~~c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(fast != nullptr) {
            fast = fast->next;
            if(n < 0) {
                slow = slow->next;
            }
            if(fast == nullptr) {
                break;
            }
            n--;
        }
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        ListNode* result = dummy->next;
        delete dummy; // 释放虚拟头节点

        return result;
    }
};
~~~
### 160.链表相交

[题目链接/解析](https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html)

难绷，我的vscode在我刚开始写循环的时候就跳出来了正确答案（就3行）
~~~c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;
    }
};

~~~
我一开始是想着弄两个指针他俩一起遍历找到长度差，
长的减短的，让长的遍历到跟短的结尾对齐，然后开始遍历，
相等就返回，正好最后不相等返回空指针也是null。
但是vscode的读了半天也没读懂，问了ai才知道它的巧妙之处。

### 142.环形链表II

[题目链接/解析](https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html)

主要考察两知识点：

- 判断链表是否环
- 如果有环，如何找到这个环的入口

一点思路可没有，看答案吧

- fast指针一定先进入环中，如果fast指针和slow指针相遇的话，一定是在环中相遇
- 从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。

根据这个思路写出代码，与答案有所不同

~~~c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pos = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                break;
            }
        }
        if(fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        while(pos != slow) {
            pos = pos->next;
            slow = slow->next;
        }
        return pos;
    }
};
~~~
---

链表第二部分有点难度，但是今天更为熟练了，希望不会三天就忘掉