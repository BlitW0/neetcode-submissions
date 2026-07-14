/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int proc = 0;

    // Inorder traversal
    int kthSmallest(TreeNode* root, int k) {
        if (not root) return -1;

        int l = kthSmallest(root->left, k);
        // count nodes inorder, when k return val
        if (++proc == k)
            return root->val;
        int r = kthSmallest(root->right, k);

        // if kth found non -1 val returned, else -1
        // so just take max and return to propagate
        return max(l, r); 
    }
};