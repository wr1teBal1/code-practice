/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// @lc code=end

