/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};
// @lc code=end

