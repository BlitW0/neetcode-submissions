/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Special algo for BST, only using values
        // for every ancestor above lca, both p and q right in either left 
        // or right subtree. at lca, both lie in opposites

        TreeNode *cur = root;
        int pval = p->val, qval = q->val;

        while (cur) {
            int curval = cur->val;
            if (pval > curval and qval > curval) // both larger, go right
                cur = cur->right;
            else if (pval < curval and qval < curval) // both smaller, go left
                cur = cur->left;
            else
                return cur;
        }

        return nullptr;
    }
};