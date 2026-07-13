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
    ListNode* reverseList(ListNode* head) {
        // list of size 0 or 1
        if (not head or not head->next) return head; 

        ListNode *newhead = reverseList(head->next);
        ListNode *nxt = head->next;
        nxt->next = head, head->next = nullptr;
        return newhead;
    }
};