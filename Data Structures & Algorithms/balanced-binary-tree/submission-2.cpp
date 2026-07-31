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
    int maxDepth(TreeNode* root, bool& bal) {
        if (not root)
            return 0;
        
        int l = maxDepth(root->left, bal);
        int r = maxDepth(root->right, bal);
        bal = bal and abs(l - r) <= 1;

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        bool bal = true;
        maxDepth(root, bal);
        return bal;
    }
};
