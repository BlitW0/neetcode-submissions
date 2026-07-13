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
        if (not head) return head;

        // head->nxt->nxt2...
        // <-head<-nxt<-nxt2<-...
        // need to store nxt to point it to head 
        // when recursion returns head of reversed list
        // starting from nxt
        ListNode *nxt = head->next;
        if (not nxt) return head;

        ListNode *rev = reverseList(nxt);
        nxt->next = head, head->next = nullptr;
        return rev;
    }
};