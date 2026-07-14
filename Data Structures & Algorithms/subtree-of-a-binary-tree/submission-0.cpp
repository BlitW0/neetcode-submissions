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
    bool equal(TreeNode* p, TreeNode* q) {
        if (not p or not q)
            return not p and not q;
        
        return (p->val == q->val)
            and equal(p->left, q->left)
            and equal(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (not root)
            return not subRoot;
        
        bool ret = false;
        if (root->val == subRoot->val)
            ret = ret or equal(root, subRoot);
        return ret or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};