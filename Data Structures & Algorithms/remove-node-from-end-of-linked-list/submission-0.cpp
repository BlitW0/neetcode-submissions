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
        ListNode *slow = head, *fast = head, *temp;

        // move fast n steps, so diff b/w both is now n
        // once fast reaches last, slow will be at n-1
        while (n--) fast = fast->next;

        if (not fast) { // delete head
            temp = head->next;
            delete head;
            return temp;
        }

        // move together, fast will be at last, slow at n-1
        while (fast->next) slow = slow->next, fast = fast->next;
        
        temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};