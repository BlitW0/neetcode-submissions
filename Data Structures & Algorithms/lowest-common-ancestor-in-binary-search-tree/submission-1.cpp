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
        // if null or found any of the 2 nodes, return them
        if (not root or root == p or root == q)
            return root;
        
        // search in left and right subtree
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        // on lca, both left and right will give p or q
        // which confirms it's the lca
        if (l and r) return root;

        return l ? l : r; // prefer non-null
    }
};