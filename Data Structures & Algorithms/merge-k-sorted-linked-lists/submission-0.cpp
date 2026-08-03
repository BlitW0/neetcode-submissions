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
    using pi = pair <int, int>;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *dummy = new ListNode(-1), *cur;
        cur = dummy;

        priority_queue <pi, vector <pi>, greater<> > pq;
        for (int i = 0; i < k; i++)
            if (lists[i])
                pq.push({lists[i]->val, i});
        
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            cur->next = lists[idx];
            cur = lists[idx];
            lists[idx] = lists[idx]->next;

            if (lists[idx])
                pq.push({lists[idx]->val, idx});
        }

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};