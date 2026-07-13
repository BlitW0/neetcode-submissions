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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur;
        ListNode *p1 = l1, *p2 = l2;
        
        int carry = 0, sum;
        cur = dummy;
        while (p1 or p2) {
            sum = carry + (p1 ? p1->val : 0) + (p2 ? p2->val : 0);
            carry = sum / 10, sum = sum % 10;

            cur->next = new ListNode(sum);
            cur = cur->next;

            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }

        if (carry) cur->next = new ListNode(carry);
        return dummy->next;
    }
};