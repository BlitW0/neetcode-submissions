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
    void reorderList(ListNode* head) {
        // Find mid
        ListNode *slow = head, *fast = head;
        while (fast and fast->next)
            slow = slow->next, fast = fast->next->next;
        
        // Reverse list starting from mid->next
        ListNode *cur = slow->next, *temp;
        ListNode *prev = slow->next = nullptr; // set mid->next null
        while (cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur, cur = temp;
        }

        // prev is head of reversed list
        // now merge by adding alternate nodes from start and reversed second half
        ListNode *midhead = prev, *tempmid; cur = head;
        while (midhead) {
            temp = cur->next;
            tempmid = midhead->next;

            cur->next = midhead;
            midhead->next = temp;
            
            cur = temp, midhead = tempmid;
        }
    }
};